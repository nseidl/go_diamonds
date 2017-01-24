while true; do
  ./seed_changer.sh
  use_seed=$(head -n 1 ../data/current_seed.txt)
  previous_roll=$(tail -1 ../data/rolls/$((use_seed))_rolls.txt)
  echo "$previous_roll" > ../data/rolls/previous_roll.txt
  ./download_html.sh
  ./parse_html $((use_seed))
  echo "$(tail -1 ../data/rolls/$((use_seed))_rolls.txt)" > ../data/rolls/current_roll.txt
  current_roll=$(tail -1 ../data/rolls/current_roll.txt)
  current_roll_int=${current_roll%%.*}
  if [[ $current_roll != *"$previous_roll"* ]]; then
    when=$(date -u +"%m/%d/%Y@%H:%M:%S");
    num_rolls_on_current_seed=$(wc -l < ../data/rolls/$((use_seed))_rolls.txt)
    echo "----------------------------------------------------------------------"
    RED='\033[0;31m'
    GREEN='\033[0;32m'
    YELLOW='\033[1;33m'
    BLUE='\033[0;34m'
    NC='\033[0m'

    if [ $current_roll_int -lt 1 ]; then
      echo -e "$when --> STARTING analysis of seed $((use_seed)) ${YELLOW}roll $((num_rolls_on_current_seed))/2400 -- $current_roll --${NC}"
    elif [ $current_roll_int -gt 47 ] && [ $current_roll_int -lt 53 ]; then
      echo -e "$when --> STARTING analysis of seed $((use_seed)) ${GREEN}roll $((num_rolls_on_current_seed))/2400 -- $current_roll --${NC}"
    elif [ $current_roll_int -gt 52 ]; then
      echo -e "$when --> STARTING analysis of seed $((use_seed)) ${BLUE}roll $((num_rolls_on_current_seed))/2400 -- $current_roll --${NC}"
    elif [ $current_roll_int -lt 48 ]; then
      echo -e "$when --> STARTING analysis of seed $((use_seed)) ${RED}roll $((num_rolls_on_current_seed))/2400 -- $current_roll --${NC}"
    fi

    if [ $((current_roll_int)) -lt 2 ] || [ $((current_roll_int)) -gt 47 ] && [ $((current_roll_int)) -lt 53 ]; then
      #echo "at $when seed $((use_seed)) roll $((num_rolls_on_current_seed))/2400 was $current_roll" | ./twilio-sms -u ACd0342e8db59e87dcb3eceb63708ced2f -p 5e4d64a7149e429c8a190805eba8e69f -d 650-900-8321 650-739-6674 &
    fi

    ./update_maxes
    ./print_stats $use_seed
    ./process_droughts $use_seed
    
    when=$(date -u +"%m/%d/%Y@%H:%M:%S");
    echo "$when --> ENDING analysis of seed $((use_seed)) roll $((num_rolls_on_current_seed))/2400 -- $current_roll --"
    echo "----------------------------------------------------------------------"

  fi

  delay=$[1+$[RANDOM%3]]
  sleep $delay
done
