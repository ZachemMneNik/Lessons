from setuptools import setup, Extension

def main():
    setup(name="VectorAndMatrixMathC",
          version="1.0.0",
          description="Python interface for the Vector and Matrix math C library function",
          author="Sinitskij Ilya",
          author_email="Sinitzkij.ilya@yandex.ru",
          ext_modules=[Extension("VectorAndMatrixMathC", ["main.c"])])

if __name__ == "__main__":
    main()
