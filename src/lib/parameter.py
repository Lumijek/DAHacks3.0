import pygame_widgets
from pygame_widgets.slider import Slider
from pygame_widgets.textbox import TextBox

class parameter:

    def __init__(self, window, x, y, width, height, fontsize, title):
        self.slider = Slider(
            window, int(x), int(y), int(width), int(height*0.8), 
            min=0, max=99, step=1, handleColour=(255, 255, 255)
        )
        self.textbox = TextBox(
            window, int(x), int(y)-50, int(width), int(height), fontSize=fontsize, radius=5
        )
        self.title = title
    
    def update(self):
        self.textbox.setText(f'{self.title}: {self.slider.getValue()}')