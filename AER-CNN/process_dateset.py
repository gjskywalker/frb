'''
Created on Fri Nov 10 11:15:55 2017

@author: Muhammad Shahnawaz

This script is to rename all the files in Samples directory with numbers. The files by default have a long name so we replaced all the file names with numbers.
'''
import os
import shutil
def rename_file(folder):
    i = 1
    for filename in os.listdir(folder):
        infilename = os.path.join(folder,filename)
        if not os.path.isfile(infilename):continue
        if infilename[len(infilename)-6:len(infilename)] == '-0.wav':
            shutil.move(infilename,'Samples/audio/dog')
        if infilename[len(infilename)-6:len(infilename)] == '-1.wav':
            shutil.move(infilename,'Samples/audio/rooster')
        if infilename[len(infilename)-6:len(infilename)] == '-2.wav':
            shutil.move(infilename,'Samples/audio/pig')
        if infilename[len(infilename)-6:len(infilename)] == '-3.wav':
            shutil.move(infilename,'Samples/audio/cow')
        if infilename[len(infilename)-6:len(infilename)] == '-4.wav':
            shutil.move(infilename,'Samples/audio/frog')
        if infilename[len(infilename)-6:len(infilename)] == '-5.wav':
            shutil.move(infilename,'Samples/audio/cat')
        if infilename[len(infilename)-6:len(infilename)] == '-6.wav':
            shutil.move(infilename,'Samples/audio/hen')
        if infilename[len(infilename)-6:len(infilename)] == '-7.wav':
            shutil.move(infilename,'Samples/audio/insects')
        if infilename[len(infilename)-6:len(infilename)] == '-8.wav':
            shutil.move(infilename,'Samples/audio/sheep')
        if infilename[len(infilename)-6:len(infilename)] == '-9.wav':
            shutil.move(infilename,'Samples/audio/crow')
        
        
        if infilename[len(infilename)-6:len(infilename)] == '10.wav':
            shutil.move(infilename,'Samples/audio/rain')
        if infilename[len(infilename)-6:len(infilename)] == '11.wav':
            shutil.move(infilename,'Samples/audio/sea_waves')
        if infilename[len(infilename)-6:len(infilename)] == '12.wav':
            shutil.move(infilename,'Samples/audio/crackling_fire')
        if infilename[len(infilename)-6:len(infilename)] == '13.wav':
            shutil.move(infilename,'Samples/audio/crickets')
        if infilename[len(infilename)-6:len(infilename)] == '14.wav':
            shutil.move(infilename,'Samples/audio/chirping_birds')
        if infilename[len(infilename)-6:len(infilename)] == '15.wav':
            shutil.move(infilename,'Samples/audio/water_drop')
        if infilename[len(infilename)-6:len(infilename)] == '16.wav':
            shutil.move(infilename,'Samples/audio/wind')
        if infilename[len(infilename)-6:len(infilename)] == '17.wav':
            shutil.move(infilename,'Samples/audio/pouring_water')
        if infilename[len(infilename)-6:len(infilename)] == '18.wav':
            shutil.move(infilename,'Samples/audio/toilet_flush')
        if infilename[len(infilename)-6:len(infilename)] == '19.wav':
            shutil.move(infilename,'Samples/audio/thunderstorm')

        if infilename[len(infilename)-6:len(infilename)] == '20.wav':
            shutil.move(infilename,'Samples/audio/crying_baby')
        if infilename[len(infilename)-6:len(infilename)] == '21.wav':
            shutil.move(infilename,'Samples/audio/sneezing')
        if infilename[len(infilename)-6:len(infilename)] == '22.wav':
            shutil.move(infilename,'Samples/audio/clapping')
        if infilename[len(infilename)-6:len(infilename)] == '23.wav':
            shutil.move(infilename,'Samples/audio/breathing')
        if infilename[len(infilename)-6:len(infilename)] == '24.wav':
            shutil.move(infilename,'Samples/audio/coughing')
        if infilename[len(infilename)-6:len(infilename)] == '25.wav':
            shutil.move(infilename,'Samples/audio/footsteps')
        if infilename[len(infilename)-6:len(infilename)] == '26.wav':
            shutil.move(infilename,'Samples/audio/laughing')
        if infilename[len(infilename)-6:len(infilename)] == '27.wav':
            shutil.move(infilename,'Samples/audio/brushing_teeth')
        if infilename[len(infilename)-6:len(infilename)] == '28.wav':
            shutil.move(infilename,'Samples/audio/snoring')
        if infilename[len(infilename)-6:len(infilename)] == '29.wav':
            shutil.move(infilename,'Samples/audio/drinking_sipping')

        if infilename[len(infilename)-6:len(infilename)] == '30.wav':
            shutil.move(infilename,'Samples/audio/door_wood_knock')
        if infilename[len(infilename)-6:len(infilename)] == '31.wav':
            shutil.move(infilename,'Samples/audio/mouse_click')
        if infilename[len(infilename)-6:len(infilename)] == '32.wav':
            shutil.move(infilename,'Samples/audio/keyboard_typing')
        if infilename[len(infilename)-6:len(infilename)] == '33.wav':
            shutil.move(infilename,'Samples/audio/door_wood_creaks')
        if infilename[len(infilename)-6:len(infilename)] == '34.wav':
            shutil.move(infilename,'Samples/audio/can_opening')
        if infilename[len(infilename)-6:len(infilename)] == '35.wav':
            shutil.move(infilename,'Samples/audio/washing_machine')
        if infilename[len(infilename)-6:len(infilename)] == '36.wav':
            shutil.move(infilename,'Samples/audio/vacuum_cleaner')
        if infilename[len(infilename)-6:len(infilename)] == '37.wav':
            shutil.move(infilename,'Samples/audio/clock_alarm')
        if infilename[len(infilename)-6:len(infilename)] == '38.wav':
            shutil.move(infilename,'Samples/audio/clock_tick')
        if infilename[len(infilename)-6:len(infilename)] == '39.wav':
            shutil.move(infilename,'Samples/audio/glass_breaking')

        if infilename[len(infilename)-6:len(infilename)] == '40.wav':
            shutil.move(infilename,'Samples/audio/helicopter')
        if infilename[len(infilename)-6:len(infilename)] == '41.wav':
            shutil.move(infilename,'Samples/audio/chainsaw')
        if infilename[len(infilename)-6:len(infilename)] == '42.wav':
            shutil.move(infilename,'Samples/audio/siren')
        if infilename[len(infilename)-6:len(infilename)] == '43.wav':
            shutil.move(infilename,'Samples/audio/car_horn')
        if infilename[len(infilename)-6:len(infilename)] == '44.wav':
            shutil.move(infilename,'Samples/audio/engine')
        if infilename[len(infilename)-6:len(infilename)] == '45.wav':
            shutil.move(infilename,'Samples/audio/train')
        if infilename[len(infilename)-6:len(infilename)] == '46.wav':
            shutil.move(infilename,'Samples/audio/church_bells')
        if infilename[len(infilename)-6:len(infilename)] == '47.wav':
            shutil.move(infilename,'Samples/audio/airplane')
        if infilename[len(infilename)-6:len(infilename)] == '48.wav':
            shutil.move(infilename,'Samples/audio/fireworks')
        if infilename[len(infilename)-6:len(infilename)] == '49.wav':
            shutil.move(infilename,'Samples/audio/hand_saw')
        #newname = os.path.join(folder,str(i)+'+'+infilename[len(infilename)-6:len(infilename)])
        #i = i + 1
        #os.rename(infilename,newname)
# code entry point
if __name__ == '__main__':
    folder = 'Samples/'
    directs = os.listdir(folder)
    for directory in directs:
        rename_file(os.path.join(folder,directory))
