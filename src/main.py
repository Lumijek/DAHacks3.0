import sys, pygame, pygame_widgets
from lib.parameter import parameter

pygame.init()

window_width, window_height = 1200, 800
window = pygame.display.set_mode((window_width, window_height))
pygame.display.set_caption("Habitable Exoplanet Simulation")

width = window_width/5
height = window_height/25
dist = parameter(window, window_width/10, window_height/10, width, height, 10)
params={dist}

circle_color = (0, 128, 255)
circle_radius = 200
circle_position = (window_width/2, window_height/2)

running = True
while running:
    events = pygame.event.get()
    for event in events:
        if event.type == pygame.QUIT:
            running = False

    window.fill((0, 0, 0))

    pygame.draw.circle(window, circle_color, circle_position, circle_radius)

    pygame_widgets.update(events)
    for param in params:
        param.update()
    pygame.display.flip()

pygame.quit()
sys.exit()
