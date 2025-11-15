import time
import random

MIN_ANGLE = 0
MAX_ANGLE = 180
STEP = 1

MIN_DISTANCE = 10
MAX_DISTANCE = 400

def fake_distance():
    # Random valid or invalid distance
    if random.random() < 0.15:
        return -1  # 15% chance of invalid reading
    return random.randint(MIN_DISTANCE, MAX_DISTANCE)

while True:
    # sweep forward
    for angle in range(MIN_ANGLE, MAX_ANGLE + 1, STEP):
        d = fake_distance()
        print(f"{angle},{d}")
        time.sleep(0.015)

    # sweep backward
    for angle in range(MAX_ANGLE, MIN_ANGLE - 1, -STEP):
        d = fake_distance()
        print(f"{angle},{d}")
        time.sleep(0.015)
