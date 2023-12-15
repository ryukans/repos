def space(x):
    y = ''
    l = len(x)
    # takes single character and concatenates space character, until the second-second last character, from x[0] to x[lenght-2]
    # where x[lenght-1] is the final character
    for i in range(l-1):
        y = y+x[i]+' '
    
    # take last character, x[lenght-1], and concatenates it with string built so far, y.
    y = y+x[l-1]

    return y

def maximum(nums, n):
    maxnum = nums[0]
    for i in range(n):
        if nums[i] > maxnum:
            maxnum = nums[i]
    
    return maxnum


_max = 15
subjects = []
grades = []
maxgrade = 10

while True:
    s = int(input("How many subjects: "))
    if s <= 0 or s > _max:
        print("Invalid data")
    else:
        break

#inserisci la materia, e per ogniuna di essa indica il voto
for i in range(s): # il ciclo si ripete per il numero totale di materie
    subject = input("Inserisci materia: ") #inserisci la materia, 'subject'
    subjects.append(subject) #inserici la meteria i-esima, 'subject', nella lista 'subjects'
    #subjects[i]=subject #iterare una lista per indicizzazione 

    #prendi voto della singola materia 
    while True:
        grade = float(input("Inserci voto: ")) # singolo voto i-esimo
        if grade < 1 or grade >= _max:
            print("Invalid grade: ")
        else:
            grades.append(grade) #inserisci il voto i-esmo nella lista 'grades'
            break

for i in range(s):
    subjects[i] = space(subjects[i])

m = maximum(grades, s)
print('Max grade is: ', m)
