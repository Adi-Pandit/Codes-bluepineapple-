text = open("Test.txt","r", encoding="utf8")

d = dict()

for line in text:
    line = line.strip()
    line = line.lower()
    words = line.split(" ")

    for word in words:
        if word in d:
            d[word] = d[word]+1
        else:   
            d[word] = 1

listOfWords = ['for','is','of','in','great','with','epic','the','and']
dictOfWords = {'for':4,'is':10,'of':55,'in':14,'great':1,'with':6,'epic':3,'the':75,'and':28}


for word in listOfWords:
    if d[word]==dictOfWords[word]:
        print("Test case successful for word",word)
    else:
        print("Test case unsuccessful for word",word)
