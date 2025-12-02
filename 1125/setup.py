
from setuptools import setup                # Import setup from setuptools
from Cython.Build import cythonize          # Import cythonize from Cython.Build
setup(                                      # Call setup function
    ext_modules = cythonize("hello.py")     # Specify the Cython file to be compiled (cythonize function is used to compile Cython files)
)

