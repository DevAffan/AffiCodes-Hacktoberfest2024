import requests

api_key = "Get Your Api_key at www.weatherapi.com"
city = input("Enter City: ")

url = f"http://api.weatherapi.com/v1/forecast.json?key={api_key}&q={city}&days=7&aqi=no&alerts=no"

response = requests.get(url)

try:
    if response.status_code == 200:
        data = response.json()
        print(f"\nCity : {data["location"]["name"]}\nState: {data["location"]["region"]}\nCountry: {data["location"]["country"]}\nTimezone: {data["location"]["tz_id"]}\n")
        for i in range(0,7):
            date = data["forecast"]["forecastday"][i]["date"]
            avg_temp = data["forecast"]["forecastday"][i]["day"]["avgtemp_c"]
            avg_humidity = data["forecast"]["forecastday"][i]["day"]["avghumidity"]
            condition = data["forecast"]["forecastday"][i]["day"]["condition"]["text"]

            print("\nDate: ", date)
            print("Average Temp: ", avg_temp)
            print("Average Humidity: ", avg_humidity)
            print("Condition: ", condition)


except:
    print("Error: ",response.status_code)
