import wikipedia as wiki

topic = input("Please enter the topic: ")
results = wiki.search(topic)
print("[+] Found", len(results), "entries!")
print("Select the article: ")
for index, value in enumerate(results):
	print(str(index)+ ")"+" "+str(value))

print("\n")
article = int(input())
try:
	page = wiki.page(results[article])
	print(str(page.title).center(1000))
	print(page.url)
	print(wiki.summary(results[article], sentences=1))
except DisambiguationError as e:
	print("[-] An error occured!")
	print("URL: "+"https://en.wikipedia.org/wiki/"+str(results[article]).replace(' ', '_'))