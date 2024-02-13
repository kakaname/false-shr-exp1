gcc main.c -o main -O0 -pthread
gcc shr.c -o shr -O0 -pthread

echo "" > example.csv

for i in {1..50}
do
    ./main >> example.csv
    ./shr >> example.csv
done

if     [ -n "$(tail -c1 example.csv)" ]    # if the file has not a trailing new line.
then
       truncate -s-1 example.csv           # remove one char as the question request.
else
       truncate -s-2 example.csv           # remove the last two characters
       echo "" >> example.csv              # add the trailing new line back
fi

