#!/bin/bash

GREEN='\033[0;32m'
RED='\033[0;31m'
BLUE='\033[0;34m'
RESET='\033[0m'

echo -e "${BLUE}=== Push Swap Tests ===${RESET}\n"

# Test 1: Arguments séparés
echo -e "${BLUE}Test 1: Arguments séparés${RESET}"
./push_swap --adaptive 4 67 3 87 23 | wc -l
echo ""

# Test 2: Arguments quotés
echo -e "${BLUE}Test 2: Arguments en string${RESET}"
./push_swap --adaptive "4 67 3 87 23" | wc -l
echo ""

# Test 3: 100 nombres
echo -e "${BLUE}Test 3: 100 nombres aléatoires${RESET}"
RESULT=$(./push_swap --simple $(shuf -i 0-999 -n 100) | wc -l)
echo "Opérations: $RESULT"
if [ $RESULT -lt 700 ]; then
    echo -e "${GREEN}✓ Excellent (<700)${RESET}"
elif [ $RESULT -lt 1500 ]; then
    echo -e "${GREEN}✓ Bon (<1500)${RESET}"
else
    echo -e "${RED}✗ Trop d'opérations${RESET}"
fi
echo ""

# Test 4: 500 nombres
echo -e "${BLUE}Test 4: 500 nombres aléatoires${RESET}"
RESULT=$(./push_swap --complex $(shuf -i 0-9999 -n 500) | wc -l)
echo "Opérations: $RESULT"
if [ $RESULT -lt 5500 ]; then
    echo -e "${GREEN}✓ Excellent (<5500)${RESET}"
elif [ $RESULT -lt 8000 ]; then
    echo -e "${GREEN}✓ Bon (<8000)${RESET}"
else
    echo -e "${RED}✗ Trop d'opérations${RESET}"
fi
echo ""

# Test 5: Benchmark
echo -e "${BLUE}Test 5: Benchmark mode${RESET}"
./push_swap --bench --adaptive $(shuf -i 0-999 -n 500) 2>&1 | grep "\[bench\]"