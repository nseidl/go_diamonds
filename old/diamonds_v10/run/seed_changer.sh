use_seed=$(head -n 1 ../data/current_seed.txt)
num_rolls_on_current_seed=$(wc -l < ../data/rolls/$((use_seed))_rolls.txt)
num_rolls_on_current_seed=${num_rolls_on_current_seed:4:4}
if [[ $num_rolls_on_current_seed == *"2400"* ]]
then
  use_seed=$((use_seed + 1))
  echo "seed updated to $use_seed"
  echo "$((use_seed))" > ../data/current_seed.txt
  echo -n > ../data/html/$((use_seed))_all_html.txt
  echo -n > ../data/rolls/$((use_seed))_rolls.txt
  echo "seed $((use_seed)) just activated" | ./twilio-sms -u ACd0342e8db59e87dcb3eceb63708ced2f -p 5e4d64a7149e429c8a190805eba8e69f -d 650-900-8321 650-739-6674 &
  echo "updated current seed to $use_seed"
#else
  #echo "using seed $use_seed"
fi
