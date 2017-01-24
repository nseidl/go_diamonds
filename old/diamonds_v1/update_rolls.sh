while true; do
  use_seed=$(head -n 1 current_seed.txt)
  num_rolls_on_current_seed=$(wc -l < $((use_seed))_rolls.txt)
  if [[ $num_rolls_on_current_seed == *"2400"* ]]
  then
    use_seed=$((use_seed + 1))
    echo "$((use_seed))" > current_seed.txt 
  else
    url=http://csgodiamonds.com/slot-rolls/$use_seed
    when=$(date +"%m/%d/%Y@%H:%M:%S");
    echo "| $when --> starting curl of $url"
    curl -s $url -H 'Accept-Encoding: gzip, deflate, sdch' -H 'Accept-Language: en-US,en;q=0.8' -H 'Upgrade-Insecure-Requests: 1' -H 'User-Agent: Mozilla/5.0 (Macintosh; Intel Mac OS X 10_11_4) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/50.0.2661.94 Safari/537.36' -H 'Accept: text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,*/*;q=0.8' -H 'Cookie: __cfduid=da82337fc038f679a590aaa88282b8eac1461452631; token=97Es4KcmavfQBptBVRKHPjdpPnMP09f3.j3PTWTl4mdD.oMZmC9jGZNy6D.ifuQqoMxG9aF7njzTrPRLCzKVLDdUU.rysQWnFbqBtM3catdK0TK.JEsa-gqjuNsb7NBq' -H 'Connection: keep-alive' --compressed -o $((use_seed))_all_html.txt
    when=$(date +"%m/%d/%Y@%H:%M:%S");
    echo "| $when --> updated $((use_seed))_all_html.txt" 
    ./parse_html $((use_seed))
    when=$(date +"%m/%d/%Y@%H:%M:%S");
    echo "| $when --> added $(tail -1 $((use_seed))_rolls.txt) to $((use_seed))_rolls.txt"
    #echo -e "\e[4m| $when --> added $(tail -1 $((use_seed))_rolls.txt) to $((use_seed))_rolls.txt\e[0m"
    delay=$[5+$[RANDOM%5]]
    echo "-------------------------"
    #echo "_________________________"
    sleep $delay
  fi
done
