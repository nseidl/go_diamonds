while true; do
  use_seed=$(head -n 1 ../data/current_seed.txt)
  ./seed_changer.sh
  use_seed=$(head -n 1 ../data/current_seed.txt)
  previous_roll=$(tail -1 ../data/rolls/$((use_seed))_rolls.txt)
  echo "$previous_roll" > ../data/rolls/previous_roll.txt
  ./download_html.sh
  #echo "previous roll $previous_roll"
  ./parse_html $((use_seed))
  echo "$(tail -1 ../data/rolls/$((use_seed))_rolls.txt)" > ../data/rolls/current_roll.txt
  current_roll=$(tail -1 ../data/rolls/current_roll.txt)
  #echo "current roll $current_roll"
  current_roll_int=${current_roll%%.*}
  
  if [[ $current_roll != *"$previous_roll"* ]]; then
    when=$(date -u +"%m/%d/%Y@%H:%M:%S");
    num_rolls_on_current_seed=$(wc -l < ../data/rolls/$((use_seed))_rolls.txt)
    num_rolls_on_current_seed=${num_rolls_on_current_seed:4:4}
    echo "$when --> STARTING analysis of roll $((num_rolls_on_current_seed))/2400 -- $current_roll --"

    ./update_maxes
    ./print_stats $use_seed
      
    RED='\033[0;31m'
    GREEN='\033[0;32m'
    YELLOW='\033[1;33m'
    BLUE='\033[0;34m'
    NC='\033[0m'

      #if [ $roll_value_int -lt 1 ]; then
        #echo -e "| $when --> starting analysis of ${YELLOW}roll $((num_rolls_on_current_seed + 1))/2400 $roll_value${NC}"
      #elif [ $roll_value_int -gt 47 ] && [ $roll_value_int -lt 53 ]; then
        #echo -e "| $when --> starting analysis of ${GREEN}roll $((num_rolls_on_current_seed + 1))/2400 $roll_value${NC}"
      #elif [ $roll_value_int -gt 52 ]; then
        #echo -e "| $when --> starting analysis of ${BLUE}roll $((num_rolls_on_current_seed + 1))/2400 $roll_value${NC}"
      #elif [ $roll_value_int -lt 48 ]; then
        #echo -e "| $when --> starting analysis of ${RED}roll $((num_rolls_on_current_seed + 1))/2400 $roll_value${NC}"
      #fi

      #./analyze_seed $use_seed
      #./update_maxes
      #if [ $roll_value_int -lt 2 ] || [ $roll_value_int -gt 47 ] && [ $roll_value_int -lt 53 ]; then
        #echo "at $when seed $((use_seed)) roll $((num_rolls_on_current_seed + 1))/2400 was $roll_value" | ./twilio-sms -u ACd0342e8db59e87dcb3eceb63708ced2f -p 5e4d64a7149e429c8a190805eba8e69f -d 650-900-8321 650-739-6674 &
      #fi
    when=$(date -u +"%m/%d/%Y@%H:%M:%S");
    echo "$when --> STARTING analysis of roll $((num_rolls_on_current_seed))/2400 -- $current_roll --"

  fi

  #update stats files
  #print out final data state
  delay=$[1+$[RANDOM%3]]
  sleep $delay
done
