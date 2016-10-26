# An example of simple (introspective) reflection.

class A:
    k = 8
    def f(x):
        return x + 1

class B(A): pass

a = A()
b = B()

# Find the classes of objects a and b.
a_class = a.__class__.__name__
b_class = b.__class__.__name__
print "class of a = " + a_class
print "class of b = " + b_class

# Figure out the class hierarchy.
print a_class + " is subclass of " + b_class + ": " + str(issubclass(a.__class__, b.__class__))
print b_class + " is subclass of " + a_class + ": " + str(issubclass(b.__class__, a.__class__))

# Discover the fields/methods of object a.
print "a contains: " + str(dir(a))
print "object a has been defined inside module: " + a.__module__
for m in dir(a):
    print "  is a." + m + " callable? " + str(callable(getattr(a, m)))
