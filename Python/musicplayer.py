from playsound import playsound
song_name=input('\nEnter Song: ')
if(song_name=='Zinda Banda'):
      playsound('C:\\Users\\Harsh Porwal\\Downloads\\Zinda Banda - Jawan.mp3')
      Stop=input('\nTo Stop type s: ')
      if(Stop=='s'):
        playsound.stop()
elif(song_name=='Jawan'):
          playsound("C:\\Users\\Harsh Porwal\\Downloads\\Jawan Prevue Theme_320(PagalWorld.cm).mp3")
          Stop=input('\nTo Stop type s: ')
          if(Stop=='s'):
            playsound.stop()
elif(song_name=='Not Ramaiya Vastavaiya'):
          playsound("C:\\Users\\Harsh Porwal\\Downloads\\Not Ramaiya Vastavaiya_320(PagalWorld.cm).mp3")
          Stop=input('\nTo Stop type s: ')
          if(Stop=='s'):
            playsound.stop()
else:
    print('Song Not Found')