"""
You have two 2D arrays with different values, the first column is a list of current ages, the first row is a list of future ages.
You are interested in knowing the value you obtain between the current age and the future age, this is something very useful to make life insurance calculations.
The probability of death is established by separate coefficients between ages and genders.

Coefficients in the example here are not official values.
More info about it in https://www.statista.com/statistics/241572/death-rate-by-age-and-sex-in-the-us/

"""
from flask import Flask, request

app = Flask(__name__)

Matrix_Males = [
    [
        0.0,# future-age expected
        70.0,
        72.0,
        74.0,
        76.0,
        78.0,
        80.0,
    ],
    [
        30.0, # current-age at 2022
        4.00300364367637,
        4.65357714634686,
        5.2975489163181715,
        6.1311908413372675,
        7.235605609427768,
        8.70580829754233,
    ],
    [
        40.0,
        3.909413049972417,
        4.5319493057593006,
        5.147291902355326,
        5.941385092247554,
        7.011089610178568,
        8.404987327877164,
    ],
    [
        41.0,
        4.597661792517911,
        5.231861173313675,
        6.070734662014499,
        7.153809057054813,
        8.618204648454181,
        10.62494317102967,
    ],
    [
        42.0,
        4.580145751193617,
        5.21234350955173,
        6.036219536571191,
        7.147247179759338,
        8.603452410551649,
        10.603562367419142,
    ],
    [
        43.0,
        3.872842245967493,
        4.496231659112897,
        5.119185423610552,
        5.931818109494922,
        7.015063174773551,
        8.508818726900186,
    ],
    [
        44.0,
        4.554836734855037,
        5.184812283905966,
        6.016337444032286,
        7.107910472128197,
        8.591872353319728,
        10.572706433178238,
    ],
    [
        45.0,
        4.538312182699055,
        5.157827807431238,
        5.966676218748206,
        7.0484491379002785,
        8.525538930345702,
        10.615502272863335,
    ],
    [
        46.0,
        3.9387449057598554,
        4.569043770377238,
        5.199890219281898,
        6.0222711332284655,
        7.093476785044529,
        8.537998155381052,
    ],
    [
        47.0,
        3.8808483498414565,
        4.507894953913798,
        5.126210302290268,
        5.942482523658613,
        7.011479951001625,
        8.535132008858744,
    ],
    [
        48.0,
        3.3843873385461025,
        3.8646558556770714,
        4.4918386229758305,
        5.116882782774912,
        5.93575523259254,
        7.027271237420505,
    ],
    [
        49.0,
        3.0052732884525604,
        3.3869253240284545,
        3.8617220140550668,
        4.478352047824337,
        5.093606610122808,
        5.8914759619007855,
    ],
    [
        50.0,
        3.872842245967493,
        4.496231659112897,
        5.119185423610552,
        5.931818109494922,
        7.015063174773551,
        8.508818726900186,
    ]
]

Matrix_Females = [
    [
        0.0,# future-age expected
        70.0,
        72.0,
        74.0,
        76.0,
        78.0,
        80.0,
    ],
    [
        30.0, # current-age at 2022
        1.6068687170988194,
        1.6877178980691414,
        1.7857670715629717,
        1.9008204893021259,
        2.0376303404617,
        2.204099757097279,
    ],
    [
        40.0,
        2.664998339360555,
        2.9912680350215854,
        3.405205982194897,
        3.94106181192387,
        4.650967437059638,
        5.595997500526454,
    ],
    [
        41.0,
        1.372346753918864,
        1.4157695179993801,
        1.465086712419301,
        1.5222564285968876,
        1.589770793237685,
        1.670259590948468,
    ],
    [
        42.0,
        3.872842245967493,
        4.496231659112897,
        5.119185423610552,
        5.931818109494922,
        7.015063174773551,
        8.508818726900186,
    ],
    [
        43.0,
        4.554836734855037,
        5.184812283905966,
        6.016337444032286,
        7.107910472128197,
        8.591872353319728,
        10.572706433178238,
    ],
    [
        44.0,
        4.538312182699055,
        5.157827807431238,
        5.966676218748206,
        7.0484491379002785,
        8.525538930345702,
        10.615502272863335,
    ],
    [
        45.0,
        3.9387449057598554,
        4.569043770377238,
        5.199890219281898,
        6.0222711332284655,
        7.093476785044529,
        8.537998155381052,
    ],
    [
        46.0,
        3.9387449057598554,
        4.569043770377238,
        5.199890219281898,
        6.0222711332284655,
        7.093476785044529,
        8.537998155381052,
    ],
    [
        47.0,
        3.3843873385461025,
        3.8646558556770714,
        4.4918386229758305,
        5.116882782774912,
        5.93575523259254,
        7.027271237420505,
    ],
    [
        48.0,
        3.0052732884525604,
        3.3869253240284545,
        3.8617220140550668,
        4.478352047824337,
        5.093606610122808,
        5.8914759619007855,
    ],
    [
        49.0,
        3.872842245967493,
        4.496231659112897,
        5.119185423610552,
        5.931818109494922,
        7.015063174773551,
        8.508818726900186,
    ],
    [
        50.0,
        2.612924735418221,
        2.9301647310321255,
        3.336139620269675,
        3.8657270205621432,
        4.571670736542799,
        5.545141448789965,
    ]
]

# Some Exceptions
class UnsupportedGender(Exception):
    """Raised when gender is not Male or Female"""
    pass

class InvalidCurrentAge(Exception):
    """Raised when current_age is not in Matrix"""
    pass

class InvalidFutureAge(Exception):
    """Raised when future_age is not in Matrix"""
    pass

def simulate_death_probability(gender: str, current_age: int, future_age: int, deaths:float, total_deaths:float) -> (dict):
    """
    proportional mortality ratio = deaths due to a specific cause / (total deaths * probability value) / 100(%).
    """
    mortality_rate = 0

    if gender == "Male":
        matrix = Matrix_Males
    elif gender == "Female":
        matrix = Matrix_Females
    else:
        raise UnsupportedGender(f"Gender {gender} is not supported.")

    rows = len(matrix)
    columns = len(matrix[0])
    row = column = -1

    # find probability_value
    # find row for age
    for i in range(rows):
        if matrix[i][0] == current_age:
            row = i
            break

    if row == -1:
        raise InvalidCurrentAge(f"Age {current_age} not found in our matrix.")

    # find col for future age
    for j in range(columns):
        if matrix[0][j] == future_age:
            column = j
            break
    if column == -1:
        raise InvalidFutureAge(f"Future age {future_age} not found in our matrix.")
        
    probability_value = matrix[row][column]

    # Calculating a Mortality Rate
    mortality_rate = (deaths / (total_deaths*probability_value) )/ 1000

    return {"gender":gender,"current_age":current_age,"future_age":future_age,"mortality_rate":mortality_rate}

# TESTING CASE
def simulate_death_probability_test(gender, current_age, future_age, deaths, total_deaths):
    mortality_rate_case = simulate_death_probability(gender=gender, current_age=current_age, future_age=future_age, deaths=deaths, total_deaths=total_deaths)

    return {"mortality_rate_case":mortality_rate_case}

print(simulate_death_probability_test("Female", current_age=45, future_age=70, deaths=10,total_deaths=500))


if __name__ == "__main__":
    app.run(debug=True)