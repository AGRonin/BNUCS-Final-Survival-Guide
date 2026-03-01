# -*- coding: utf-8 -*-

from setuptools import setup, find_packages

"""
打包的用的setup必须引入
"""

VERSION = '0.7.1'

setup(name='p3d_utils',
      version=VERSION,
      description="pytorch3d tutorials utils package",
      long_description='pytorch3d tutorials utils package',
      classifiers=[],  # Get strings from http://pypi.python.org/pypi?%3Aaction=list_classifiers
      keywords='p3d_utils',
      author='lyh',
      author_email='liyuhui@mail.bnu.edu.cn',
      license='MIT',
      packages=find_packages(),
      include_package_data=True,
      zip_safe=True,
      python_requires = '>=3.9',
      install_requires=[
        'matplotlib',
        'numpy',
        'torch',
        'pytorch3d',
      ]
      )