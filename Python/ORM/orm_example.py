from sqlobject import *

sqlhub.processConnection = connectionForURI('sqlite:/:memory:')


class Person(SQLObject):
    fname = StringCol()
    mi = StringCol(length=1, default=None)
    lname = StringCol()


if __name__ == '__main__':
    Person.createTable()
    p = Person(fname="John", lname="Doe")
    p.mi = 'Q'
    p2 = Person.get(1)
    print p2
    print(p is p2)
    p3 = Person.selectBy(lname="Doe")[0]
    print p3
    pc = Person.selectBy(lname="Doe").count()
    print pc