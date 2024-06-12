
# weight converter
weight = int(input('Weight:'))
unit = input('L for lbs/K for kg:').upper()

if unit == 'K':
    print(f'Your weight is {weight*2.20462262} pounds.')
else:
    print(f'Your weight is {weight/2.20462262} pounds.')
