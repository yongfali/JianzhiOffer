from xml.dom import minidom
import urllib
import requests
 
KEY = 'AIzaSyDSdgNW9HzBicXGVCOFq5edjPFSXABZ44Y' #此处添加自己在Google地图上申请的API_KEY
 
class GetData(object):
    def __init__(self):
        self.values = {'q': '', 
                'sensor': 'false', 
                 'output': 'xml', 
                 'oe': 'utf8'}
        self.url = 'http://maps.google.com/maps/geo'
 
    def catchData(self, city, key=KEY):
        
        self.values['q'] = city
        arguments = urllib.parse.urlencode(self.values)
        url_get = self.url + '?' + arguments
        handler = urllib.request.urlopen(url_get)
        try:
            self.lon, self.lat = self.parseXML(handler)
            return self.lon, self.lat
        except IndexError:
             print ('城市: %s 发生异常！' % (city,))
        finally:
            handler.close()
         
    def parseXML(self, handler):
         '''
         解析从API上获取的XML数据。
         '''
         xml_data = minidom.parse(handler)
         data = xml_data.getElementsByTagName('coordinates')[0].firstChild.data
         coordinates = data.split(',')
         lon = int(float(coordinates[0]) * 1000000)
         lat = int(float(coordinates[1]) * 1000000)
         return lon, lat
         
if __name__ == '__main__':
     getData = GetData()
     cityName = input('请输入一个城市：')
     longitude, latitude = getData.catchData(cityName)
     print ('%s \n经度：%d\n纬度：%d\n' % (cityName, longitude, latitude))
