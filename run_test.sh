echo "Compiling..."
gcc -o bin/test ./test/*.c
if [ $? == 0 ]
then
  ./bin/test
  rm bin/test
else
  echo "Compilation Error."
fi