import matplotlib.pyplot as plt 
import csv 
  
x = [] 
y = [] 

with open('origin.csv','r') as csvfile: 
    lines = csv.reader(csvfile, delimiter=',') 
    for row in lines: 
        y.append(float(row[0])) 
        x.append(float(row[1])) 


plt.plot(y, x, color = 'g', linestyle = 'dashed', 
         marker = 'o',label = "Help Me") 

plt.xticks(rotation = 25) 
plt.xlabel('X') 
plt.ylabel('F(X)') 
plt.title('Help me', fontsize = 20) 
plt.grid() 
plt.legend() 
plt.show()
plt.clf()

y.clear()
x.clear()

with open('real.csv','r') as csvfile: 
    lines = csv.reader(csvfile, delimiter=',') 
    for row in lines: 
        y.append(float(row[0])) 
        x.append(float(row[1])) 


plt.plot(y, x, color = 'g', linestyle = 'dashed', 
         marker = 'o',label = "real") 
  
plt.xticks(rotation = 25) 
plt.xlabel('X') 
plt.ylabel('F(X)') 
plt.title('real', fontsize = 20) 
plt.grid() 
plt.legend() 
plt.show()
plt.clf()

y.clear()
x.clear()

with open('imag.csv','r') as csvfile: 
    lines = csv.reader(csvfile, delimiter=',') 
    for row in lines: 
        y.append(float(row[0])) 
        x.append(float(row[1])) 


plt.plot(y, x, color = 'g', linestyle = 'dashed', 
         marker = 'o',label = "imag") 
  
plt.xticks(rotation = 25) 
plt.xlabel('X') 
plt.ylabel('F(X)') 
plt.title('imag', fontsize = 20) 
plt.grid() 
plt.legend() 
plt.show()
plt.clf()

y.clear()
x.clear()

with open('ABS.csv','r') as csvfile: 
    lines = csv.reader(csvfile, delimiter=',') 
    for row in lines: 
        y.append(float(row[0])) 
        x.append(float(row[1])) 


plt.plot(y, x, color = 'g', linestyle = 'dashed', 
         marker = 'o',label = "ABS") 
  
plt.xticks(rotation = 25) 
plt.xlabel('X') 
plt.ylabel('F(X)') 
plt.title('ABS', fontsize = 20) 
plt.grid() 
plt.legend() 
plt.show()
plt.clf()

y.clear()
x.clear()

with open('restore.csv','r') as csvfile: 
    lines = csv.reader(csvfile, delimiter=',') 
    for row in lines: 
        y.append(float(row[0])) 
        x.append(float(row[1])) 


plt.plot(y, x, color = 'g', linestyle = 'dashed', 
         marker = 'o',label = "restore") 
  
plt.xticks(rotation = 25) 
plt.xlabel('X') 
plt.ylabel('F(X)') 
plt.title('restore', fontsize = 20) 
plt.grid() 
plt.legend() 
plt.show()
plt.clf()