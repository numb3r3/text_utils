

init:
	pip install pipenv --upgrade
	pipenv install --dev --skip-lock
test:
	# This runs all of the tests, on both Python 2 and Python 3.
	detox

flake8:
	pipenv run flake8 --ignore=E501,F401,E128,E402,E731,F821 text_utils

coverage:
	pipenv run py.test --cov-config .coveragerc --verbose --cov-report term --cov-report xml --cov=text_utils tests


publish:
	pip install 'twine>=1.5.0'
	python setup.py sdist bdist_wheel
	twine upload dist/*
	rm -fr build dist .egg text_utils.egg-info