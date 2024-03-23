file="result"
for _ in {0..300}; do
	ARG=$(seq -3000 3000 | shuf -n 100 | tr '\n' ' ')
	res=$(./push_swap "$ARG" | ./checker "$ARG")
	if [[ $res == "KO" ]]; then
		echo "here"
		echo "$ARG" >> $file
		printf "\n\n" >> $file
	fi
done
