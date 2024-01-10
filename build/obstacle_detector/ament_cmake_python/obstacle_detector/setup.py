from setuptools import find_packages
from setuptools import setup

setup(
    name='obstacle_detector',
    version='1.0.0',
    packages=find_packages(
        include=('obstacle_detector', 'obstacle_detector.*')),
)
