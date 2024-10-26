import pygame_widgets
from pygame_widgets.slider import Slider
from pygame_widgets.textbox import TextBox

class parameter:

    def __init__(self, window, x, y, width, height, fontsize):
        self.slider = Slider(
            window, int(x), int(y), int(width), int(height), 
            min=0, max=99, step=1, handleColour=(255, 255, 255)
        )
        self.textbox = TextBox(
            window, int(x), int(y)-50, int(width), int(height),
            fontsize=fontsize
        )
    
    def update(self):
        self.textbox.setText(f'Planet Distance: {self.slider.getValue()}')