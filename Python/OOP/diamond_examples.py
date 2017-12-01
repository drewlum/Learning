class A(object):
    def go(self):
        print "A called"

class B(A):
    def go(self):
        print "B called"
        super(B, self).go()

class B2(A):
    def go(self):
        print "B called"
        A.go(self)
        
class C(A):
    def go(self):
        print "C called"
        super(C, self).go()

        
class D_CB(C,B):
    def go(self):
        print "D called"
        super(D_CB, self).go()
    
class D_BC(B, C):
    def go(self):
        print "D called"
        super(D_BC, self).go()
    
class E_BC(B, C):
    def go(self):
        print('E called')
        B.go(self)

class E_B2C(B2, C):
    def go(self):
        print('E called')
        B2.go(self)

  
d_bc = D_BC()
d_cb = D_CB()
e_bc = E_BC()
e_b2c = E_B2C()

print('D_BC:  B before C\n--------')
d_bc.go()


print('\n\nD_CB:   C before B\n-------')
d_cb.go()

print('\n\nE_BC:   B before C\n-------')
e_bc.go()

print('\n\nE_B2C:   B2 before C\n-------')
e_b2c.go()


x = (1,2)
my_set = set([])
my_set.add(x)
print my_set
print "\n\n\n"

import time

def squares(n):
    for i in range(n):
        time.sleep(2)
        yield i ** 2
        
out = squares(5)
print time.time(), 'sleeping now'
#time.sleep(10)
print time.time(), 'calling next'
print time.time(), next(out)
print time.time(), next(out)
print time.time(), next(out)
print time.time(), next(out)
print time.time(), next(out)
#print time.time(), next(out)

another = list(squares(10))
print another
