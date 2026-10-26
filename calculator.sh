#!/bin/bash

ch=0
while [ $ch -ne 6 ]
do
    echo ""
    echo "===== CALCULATOR ====="
    echo "1. Addition"
    echo "2. Subtraction"
    echo "3. Multiplication"
    echo "4. Division"
    echo "5. Modulus"
    echo "6. Exit"
    read -p "Enter your choice: " ch

    if [ $ch -ge 1 ] && [ $ch -le 5 ]
    then
        read -p "Enter two numbers: " a b
    fi

    case $ch in
        1) echo "Result = $((a + b))" ;;
        2) echo "Result = $((a - b))" ;;
        3) echo "Result = $((a * b))" ;;
        4) if [ $b -eq 0 ]
           then
               echo "Cannot divide by zero"
           else
               echo "Result = $((a / b))"
           fi ;;
        5) if [ $b -eq 0 ]
           then
               echo "Cannot divide by zero"
           else
               echo "Result = $((a % b))"
           fi ;;
        6) echo "Bye" ;;
        *) echo "Invalid choice" ;;
    esac
done
