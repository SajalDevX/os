#!/bin/bash
file="employeebook.txt"

while true
do
  echo "1) Create  2) View  3) Insert  4) Delete  5) Modify  6) Exit"
  read -p "Enter choice: " ch

  case $ch in
    1) > $file; echo "Employee book created.";;
    2) cat $file;;
    3) read -p "Emp No: " eno
       read -p "Name: " name
       read -p "Mobile: " mob
       echo "$eno,$name,$mob" >> $file;;
    4) read -p "Enter Emp No to delete: " eno
       grep -v "^$eno," $file > temp && mv temp $file;;
    5) read -p "Enter Emp No to modify: " eno
       grep -v "^$eno," $file > temp
       read -p "New Emp No: " neno
       read -p "New Name: " nname
       read -p "New Mobile: " nmob
       echo "$neno,$nname,$nmob" >> temp
       mv temp $file;;
    6) echo "Goodbye!"; exit;;
    *) echo "Invalid choice";;
  esac
done
