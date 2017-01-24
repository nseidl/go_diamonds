while true; do
  use_seed=$(head -n 1 ../data/current_seed.txt)
  num_rolls_on_current_seed=$(wc -l < ../data/$((use_seed))_rolls.txt)
  num_rolls_on_current_seed=${num_rolls_on_current_seed:4:4}
  if [[ $num_rolls_on_current_seed == *"2400"* ]]
  then
    use_seed=$((use_seed + 1))
    echo "$((use_seed))" > ../data/current_seed.txt 
  else
    url=http://csgodiamonds.com/slot-rolls/$use_seed
    when=$(date +"%m/%d/%Y@%H:%M:%S");
    echo "| $when --> starting curl of $url"
    curl -s $url -H 'Accept-Encoding: gzip, deflate, sdch' -H 'Accept-Language: en-US,en;q=0.8' -H 'Upgrade-Insecure-Requests: 1' -H 'User-Agent: Mozilla/5.0 (Macintosh; Intel Mac OS X 10_11_4) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/50.0.2661.94 Safari/537.36' -H 'Accept: text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,*/*;q=0.8' -H 'Cookie: __cfduid=da82337fc038f679a590aaa88282b8eac1461452631; token=97Es4KcmavfQBptBVRKHPjdpPnMP09f3.j3PTWTl4mdD.oMZmC9jGZNy6D.ifuQqoMxG9aF7njzTrPRLCzKVLDdUU.rysQWnFbqBtM3catdK0TK.JEsa-gqjuNsb7NBq' -H 'Connection: keep-alive' --compressed -o ../data/$((use_seed))_all_html.txt
    #if there hasn't been a new number dded, don't do anything
    when=$(date +"%m/%d/%Y@%H:%M:%S");
    echo "| $when --> updated $((use_seed))_all_html.txt" 
    ./parse_html ../data/$((use_seed))
    when=$(date +"%m/%d/%Y@%H:%M:%S");
    echo "| $when --> added $(tail -1 ../data/$((use_seed))_rolls.txt) to $((use_seed))_rolls.txt"
    echo "| $when --> $num_rolls_on_current_seed/2400 rolls done on seed $use_seed"
    delay=$[5+$[RANDOM%5]]
    echo "-------------------------"
    sleep $delay
  fi
done
