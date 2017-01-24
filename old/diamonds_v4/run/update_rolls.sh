#TODO:
#-	fix new seed detection and resetting
#-	get the curl constantly every x number of seconds (randomized to within 3 seconds. Do this every 40s, starting from :00seconds
while true; do
  use_seed=$(head -n 1 ../data/current_seed.txt)
  num_rolls_on_current_seed=$(wc -l < ../data/$((use_seed))_rolls.txt)
  num_rolls_on_current_seed=${num_rolls_on_current_seed:4:4}
  if [[ $num_rolls_on_current_seed == *"2400"* ]]
  then
    use_seed=$((use_seed + 1))
    echo "$((use_seed))" > ../data/current_seed.txt 
    echo -n > ../data/$((use_seed))_all_html.txt
    echo -n > ../data/$((use_seed))_rolls.txt
    echo "seed $((use_seed)) just activated" | ./twilio-sms -u ACd0342e8db59e87dcb3eceb63708ced2f -p 5e4d64a7149e429c8a190805eba8e69f -d 650-900-8321 650-739-6674 &
  else
    url=http://csgodiamonds.com/slot-rolls/$use_seed
    previous_roll=$(tail -1 ../data/$((use_seed))_rolls.txt)
    #curl -s $url -H 'Accept-Encoding: gzip, deflate, sdch' -H 'Accept-Language: en-US,en;q=0.8' -H 'Upgrade-Insecure-Requests: 1' -H 'User-Agent: Mozilla/5.0 (Macintosh; Intel Mac OS X 10_11_4) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/50.0.2661.94 Safari/537.36' -H 'Accept: text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,*/*;q=0.8' -H 'Cookie: __cfduid=da82337fc038f679a590aaa88282b8eac1461452631; token=97Es4KcmavfQBptBVRKHPjdpPnMP09f3.j3PTWTl4mdD.oMZmC9jGZNy6D.ifuQqoMxG9aF7njzTrPRLCzKVLDdUU.rysQWnFbqBtM3catdK0TK.JEsa-gqjuNsb7NBq' -H 'Connection: keep-alive' --compressed -o ../data/$((use_seed))_all_html.txt
    curl -s $url -H 'Accept-Encoding: gzip, deflate, sdch' -H 'Accept-Language: en-US,en;q=0.8' -H 'Upgrade-Insecure-Requests: 1' -H 'User-Agent: Mozilla/5.0 (Macintosh; Intel Mac OS X 10_11_4) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/50.0.2661.94 Safari/537.36' -H 'Accept: text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,*/*;q=0.8' -H 'Connection: keep-alive' --compressed -o ../data/$((use_seed))_all_html.txt
    ./parse_html ../data/$((use_seed))
    when=$(date -u +"%m/%d/%Y@%H:%M:%S");
    roll_value=$(tail -1 ../data/$((use_seed))_rolls.txt)
    roll_value_int=${roll_value%%.*}
    if [[ $roll_value != *"$previous_roll"* ]]; then
      RED='\033[0;31m'
      GREEN='\033[0;32m'
      YELLOW='\033[1;36m'
      BLUE='\033[0;34m'
      NC='\033[0m'
      echo "-------------------------"
      
      if [ $roll_value_int -lt 1 ]; then
        echo -e "| $when --> added new ${YELLOW}roll $((num_rolls_on_current_seed + 1))/2400 $roll_value${NC} to $((use_seed))_rolls.txt" 
      elif [ $roll_value_int -gt 47 ] && [ $roll_value_int -lt 53 ]; then
        echo -e "| $when --> added new ${GREEN}roll $((num_rolls_on_current_seed + 1))/2400 $roll_value${NC} to $((use_seed))_rolls.txt"
      elif [ $roll_value_int -gt 52 ]; then
        echo -e "| $when --> added new ${BLUE}roll $((num_rolls_on_current_seed + 1))/2400 $roll_value${NC} to $((use_seed))_rolls.txt"
      elif [ $roll_value_int -lt 48 ]; then
        echo -e "| $when --> added new ${RED}roll $((num_rolls_on_current_seed + 1))/2400 $roll_value${NC} to $((use_seed))_rolls.txt"
      fi

      #echo -e "| $when --> added new roll $roll_value to $((use_seed))_rolls.txt"
      #echo "| $when --> $((num_rolls_on_current_seed + 1))/2400 rolls done on seed $use_seed"
      #echo "-------------------------"
      if [ $roll_value_int -lt 2 ] || [ $roll_value_int -gt 47 ] && [ $roll_value_int -lt 53 ]; then
        echo "at $when seed $((use_seed)) roll $((num_rolls_on_current_seed + 1))/2400 was $roll_value" | ./twilio-sms -u ACd0342e8db59e87dcb3eceb63708ced2f -p 5e4d64a7149e429c8a190805eba8e69f -d 650-900-8321 650-739-6674 &
      fi 
      #echo "-------------------------"
    fi
    delay=$[1+$[RANDOM%2]] 
    #delay=1
    #echo "| $when --> waiting $delay seconds until next curl"
    sleep $delay
  fi
done
