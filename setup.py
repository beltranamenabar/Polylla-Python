from glob import glob
from setuptools import setup
from pybind11.setup_helpers import Pybind11Extension, build_ext

ext_modules = [
    Pybind11Extension(
        "Polylla",
        ["src/main.cpp"],
        include_dirs=["extern/Polylla/src"],
        extra_compile_args=["-std=c++17", "/std:c++17"],
    ),
]

setup(
    name="Polylla",
    version="0.1.0",
    author="Beltrán Amenábar",
    description="Polygonal meshing algorithm based on terminal-edge regions",
    cmdclass={"build_ext": build_ext},
    ext_modules=ext_modules,
)
