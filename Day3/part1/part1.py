# Define a function to check if a neighbor is a symbol.
def is_symbol(c):
    return not c.isdigit() and c != '.'

# Define a function to check if a position is safe to explore.
def is_safe(i, j, rows, cols):
    return 0 <= i < rows and 0 <= j < cols

# Define a function to check if any neighbor of a cell contains a symbol.
def neighbor_contains_symbol(grid, i, j, rows, cols):
    directions = [(-1, -1), (-1, 0), (-1, 1), (0, -1), (0, 1), (1, -1), (1, 0), (1, 1)]
    for di, dj in directions:
        if is_safe(i + di, j + dj, rows, cols) and is_symbol(grid[i + di][j + dj]):
            return True
    return False

# Read the schematic from a file
schematic = []
with open('input1', 'r') as file:  # Replace 'schematic.txt' with your file's name
    for line in file:
        schematic.append(line.strip())  # .strip() removes any trailing newline characters

# Calculate the sum of all valid part numbers.
rows = len(schematic)
cols = len(schematic[0]) if rows > 0 else 0
sum_of_part_numbers = 0
possible_part_number = ''
valid_part_number = False

for i in range(rows):
    for j in range(cols):
        if schematic[i][j].isdigit():
            possible_part_number += schematic[i][j]
            if neighbor_contains_symbol(schematic, i, j, rows, cols):
                valid_part_number = True
        else:
            if valid_part_number and possible_part_number:
                sum_of_part_numbers += int(possible_part_number)
                print('Sum1', sum_of_part_numbers)
                print('Part number', possible_part_number)
            possible_part_number = ''
            valid_part_number = False
    # Check if the last number in a row is a valid part number
    if valid_part_number and possible_part_number:
        sum_of_part_numbers += int(possible_part_number)
        print('Sum2', sum_of_part_numbers)
    possible_part_number = ''
    valid_part_number = False

print(sum_of_part_numbers)
