import csv

counter = 0

def read_csv(filename):
    global counter
    odd_values = []
    even_values = []
    with open(filename, newline='') as csvfile:
        reader = csv.reader(csvfile)
        for row in reader:
            for index, value in enumerate(row):
                if index % 2 == 0:
                    even_values.append(float(value))
                    counter += 1
                else:
                    odd_values.append(float(value))

    return even_values, odd_values

# Example usage:
filename = 'example.csv'  # Replace with your CSV file name
even_values, odd_values = read_csv(filename)

print("No False-Sharing Performance:", sum(even_values)/counter)
print("False-Sharing Performance:", sum(odd_values)/counter)
