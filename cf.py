#!/usr/local/bin/python3
import requests
from bs4 import BeautifulSoup
from sys import argv
import os
import shutil

if len(argv) != 3:
    print('usage: python cf.py <contest> <problem>')
    exit()
contest, problem = argv[1:]
problem_dir = f'{contest}{problem}'

response = requests.get(f'https://codeforces.com/contest/{contest}/problem/{problem}', allow_redirects=False)
# print(response.status_code)
if response.status_code != 200:
    print('no such problem')
    exit()

shit = BeautifulSoup(response.text, "html.parser")

inputs = [i.find('pre').string.lstrip('\n') for i in shit.find_all('div', class_='input')]
outputs = [i.find('pre').string.lstrip('\n') for i in shit.find_all('div', class_='output')]
assert len(inputs) == len(outputs)

try:
    os.mkdir(problem_dir)
except FileExistsError:
    print(f'directory {problem_dir} already exists')
    exit()
shutil.copyfile('template.cpp', f'{problem_dir}/sol.cpp')
os.chdir(problem_dir)

for i in range(len(inputs)):
    with open(f'in{i + 1}.txt', 'w') as in_file, open(f'out{i + 1}.txt', 'w') as out_file:
        in_file.write(inputs[i])
        out_file.write(outputs[i])
 
print(f'problem directory {problem_dir} successfully created')
# print('input')
# print(inputs)
# print('output')
# print(outputs)

