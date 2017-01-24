current_seed=$(head -n 1 current_seed.txt)
seed=$current_seed
while true; do
  echo "trying seed $seed"
  curl -s "http://csgodiamonds.com/slot-rolls/$seed" -o test.txt
  if grep -q slot-result "test.txt"; then
    echo "seed $seed is VALID"
    echo "set current_seed.txt to $seed"
    echo $seed > current_seed.txt
  else
    echo "seed $seed is INVALID"
    rm test.txt
    exit
  fi
  seed=$((seed + 1))
  sleep 1
done

#assign values to seed info from text file
#if the next seed is valid, update current seeds
#check if currentseed+1 is active. if it is, restart get rolls with new seed

