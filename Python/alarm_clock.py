import datetime
import time
from playsound import playsound

def set_alarm(alarm_time):
    while True:
        # Get the current time
        current_time = datetime.datetime.now().strftime("%H:%M:%S")
        print(f"Current Time: {current_time}", end="\r")

        # Check if current time matches the alarm time
        if current_time == alarm_time:
            print("\nWake up! It's time!")
            playsound('alarm_sound.mp3')  # Specify your sound file here
            break

        # Wait for 1 second before checking the time again
        time.sleep(1)

if __name__ == "__main__":
    # Get user input for the alarm time in HH:MM:SS format
    alarm_time = input("Enter the alarm time (HH:MM:SS): ")
    set_alarm(alarm_time)
