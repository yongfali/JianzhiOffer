import requests,os,re
os.chdir("C:\\Users\\liyon\Desktop\\test\\downloads")
m=0
a=1
st=input("图片搜索：")
while m<3:
    url="https://image.baidu.com/search/flip?tn=baiduimage&ie=utf-8&word="+st+"&pn="+str(20*m)+"&gsm=0&ct=&ic=0&lm=-1&width=0&height=0"
    http=requests.get(url).text
    # print(http)
    photore=re.compile('"thumbURL":"(.*?)"')
    co=photore.findall(http)
    for i in co:
        try:
            pic=requests.get(i)
            f=open(str(a)+".jpg","wb")
            f.write(pic.content)
            f.close()
        except:
            print("图片无法下载")
            continue
        a=a+1
    m=m+1
