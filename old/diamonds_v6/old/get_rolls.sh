while true; do

  use_seed=$(head -n 1 current_seed.txt)
  curl -s "http://csgodiamonds.com/slot-rolls/$((use_seed + 1))" -o test.txt
  echo "the current seed is $use_seed"

  if grep -q slot-result "test.txt"; then
    echo "next seed detected to be active, updating current_seed.txt"
    use_seed=$((use_seed + 1))
    echo "$((use_seed))" > current_seed.txt
  else
    curl -s "http://csgodiamonds.com/slot-rolls/$1" -H 'Accept-Encoding: gzip, deflate, sdch' -H 'Accept-Language: en-US,en;q=0.8' -H 'Upgrade-Insecure-Requests: 1' -H 'User-Agent: Mozilla/5.0 (Macintosh; Intel Mac OS X 10_11_4) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/50.0.2661.94 Safari/537.36' -H 'Accept: text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,*/*;q=0.8' -H 'Cookie: __cfduid=da82337fc038f679a590aaa88282b8eac1461452631; token=97Es4KcmavfQBptBVRKHPjdpPnMP09f3.j3PTWTl4mdD.oMZmC9jGZNy6D.ifuQqoMxG9aF7njzTrPRLCzKVLDdUU.rysQWnFbqBtM3catdK0TK.JEsa-gqjuNsb7NBq' -H 'Connection: keep-alive' --compressed -o $1_all_html.txt
    when=$(date +"%m/%d/%Y @ %H:%M:%S");
    echo "$when ----- updated $1_all_html.txt with current rolls"
    ./parse_html $1
    echo "$1_rolls.txt has been updated"
    echo "most recent roll recorded: $(tail -1 $1_rolls.txt)"
    delay=$[5+$[RANDOM%5]]
    echo "delay until next is $delay"
    sleep $delay
  fi
done









