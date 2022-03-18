mark = float(input("mark: "))

if (mark<5):
    print("suspenso") #F in Spain

else:
    if (mark<6):
        print("suficiente") #D in Spain

    else:
        if (mark<7):
            print("bien") #C in Spain
        
        else:
           
            if (mark<9):
                print("notable") #B in Spain

            else:

                if (mark<=10):
                    print("sobresaliente") #A in Spain

                else:
                    print("tu nota no es valida, esta por encima de 10") #your mark is not valid


            
