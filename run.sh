echo "Compiling..."
gcc -o bin/main *.c
if [ $? == 0 ]
then
  ./bin/main
  rm bin/main
else
  echo "Compilation Error."
fi