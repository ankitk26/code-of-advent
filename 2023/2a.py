n = 100

tests: list[str] = []
while n != 0:
    s = input()
    tests.append(s)
    n -= 1

sum = 0
for index, test in enumerate(tests):
    r, g, b = 0, 0, 0

    sets = [x.strip() for x in test.split(":")][1]
    draws = [x.strip() for x in sets.split(";")]
    for draw in draws:
        cubes = [cube.strip() for cube in draw.split(",")]
        for cube in cubes:
            [count, color] = [x.strip() for x in cube.split(" ")]

            actual_count = int(count)

            if color == "blue":
                b = max(b, actual_count)
            if color == "red":
                r = max(r, actual_count)
            if color == "green":
                g = max(g, actual_count)

    print(r, g, b)
    sum += r * g * b

print(sum)
