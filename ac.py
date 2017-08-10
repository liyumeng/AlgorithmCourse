class Node(object):
    def __init__(self):
        self.next={}
        self.fail=None
        self.content=None
        self.cnt=0
        self.length=0
        
class AhoCorasick(object):
    def __init__(self):
        self.root=Node()
        pass
    
    def append(self,content):
        p=self.root
        for c in content:
            if c not in p.next:
                p.next[c]=Node()
            p=p.next[c]
        p.cnt+=1
        p.length=len(content)
        p.content=content
        
    def step(self,root,p,c):
        #从p节点向下走一步，寻找c
        #p节点有很多，所以需要循环遍历所有的p节点
        #p节点间是通过fail指针相连的
        #最后连到root指针上，再连到None上
        #如果没找到，返回root
        while p:
            if c in p.next:
                p=p.next[c]
                break
            p=p.fail
        if p is None:
            p=root
        return p
    
    def build(self):
        from queue import Queue
        q=Queue()
        q.put(self.root)
        while q.empty()==False:
            t=q.get()
            for c in t.next:
                # 一个节点的失效指针是(它父节点的失效指针向下走一步)
                t.next[c].fail=self.step(self.root,t.fail,c)
                q.put(t.next[c])
                
    def find(self,content):
        p=self.root
        res=[]
        for i,c in enumerate(content):
            #每次从p节点走一步寻找c
            p=self.step(self.root,p,c)
            tmp=p
            while tmp is not self.root:
                if tmp.cnt>0:
                    res.append((tmp.content,i-tmp.length+1,tmp.length))
                tmp=tmp.fail
        return res
        
if __name__=='__main__':
    ac=AhoCorasick()

    ac.append('你好中国')
    ac.append('北京')

    ac.build()

    res=ac.find('你好中国北京')
    print(res)