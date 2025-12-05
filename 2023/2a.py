n = 100

tests: list[str] = []
while n != 0:
    s = input()
    tests.append(s)
    n -= 1

sum = 0
RED, BLUE, GREEN = 12, 14, 13

for index, test in enumerate(tests):
    flag = 0

    sets = [x.strip() for x in test.split(":")][1]
    draws = [x.strip() for x in sets.split(";")]
    for draw in draws:
        cubes = [cube.strip() for cube in draw.split(",")]
        for cube in cubes:
            [count, color] = [x.strip() for x in cube.split(" ")]

            actual_count = int(count)

            if color == "blue" and actual_count > BLUE:
                flag = 1
            if color == "red" and actual_count > RED:
                flag = 1
            if color == "green" and actual_count > GREEN:
                flag = 1

    if flag == 0:
        sum += index + 1

print(sum)
