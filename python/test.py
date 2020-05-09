with open('Teacher_Fam_Message.txt', 'r') as f1:
    List = f1.readlines()
l = []
for i in range(0, len(List)):
    tmp = List[i].rstrip('\n')
    tmp = tmp + " j2020" + "%03d" % i + "\n"
    l.append(tmp)
print(l)

f=open("Teacher_Fam_Message.txt","w")
 
f.writelines(l)
f.close()