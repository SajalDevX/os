#!/bin/bash
file="addressbook.txt"

while true
do
  echo "1) Create  2) View  3) Insert  4) Delete  5) Modify  6) Exit"
  read -p "Enter choice: " ch

  case $ch in
    1) > $file; echo "Address book created.";;
    2) cat $file;;
    3) read -p "Name: " n; read -p "Phone: " p; echo "$n,$p" >> $file;;
    4) read -p "Enter name to delete: " n; grep -v "^$n," $file > temp && mv temp $file;;
    5) read -p "Enter name to modify: " n
       grep -v "^$n," $file > temp
       read -p "New Name: " nn; read -p "New Phone: " np
       echo "$nn,$np" >> temp; mv temp $file;;
    6) echo "Bye!"; exit;;
    *) echo "Invalid choice";;
  esac
done
