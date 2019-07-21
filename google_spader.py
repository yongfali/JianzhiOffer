import requests
import os

KEY = 'AIzaSyADhG9fd9clSBALf6Rpo8Wpe72y5H5VRPE'
# print("kkk")
def download(url, path):
    with requests.Session() as sess:
        con = sess.get(url, timeout = 10)
        with open(path, 'wb') as tf:
            f.write(con.content)
            print('Pic Saved!')  

if __name__ == '__main__':
    path = os.getcwd() + '\\1.jpg'
    url = "https://maps.googleapis.com/maps/api/streetview?size=600x300&location=-26.0239132,22.4003715&heading=151.78&pitch=-0.76&key=" + KEY 
    download(url, path)
