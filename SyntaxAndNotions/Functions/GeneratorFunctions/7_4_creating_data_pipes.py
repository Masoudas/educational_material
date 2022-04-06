"""
Because generators are lazy iterators, we can use them to analyze large files.

Here's how to analyze a csv file like below and then get the total sum of investments (of course, we must use
the csvmodule of python, but here we want to show an example. A pndas use would also be great to deploy a
function on a column.)

permalink,company,numEmps,category,city,state,fundedDate,raisedAmt,raisedCurrency,round
digg,Digg,60,web,San Francisco,CA,1-Dec-06,8500000,USD,b
digg,Digg,60,web,San Francisco,CA,1-Oct-05,2800000,USD,a
facebook,Facebook,450,web,Palo Alto,CA,1-Sep-04,500000,USD,angel
facebook,Facebook,450,web,Palo Alto,CA,1-May-05,12700000,USD,a
"""

file_name = "techcrunch.csv"
lines = (line for line in open(file_name))
list_line = (s.rstrip().split(",") for s in lines)	# making fields out of lines
cols = next(list_line)	# Skip the first line
company_dicts = (dict(zip(cols, data)) for data in list_line)	# Create a dictionary with column name and
	# values for each line. That way, we have dictionary for each company.

funding = (
    int(company_dict["raisedAmt"])
    for company_dict in company_dicts
    if company_dict["round"] == "a"
)

total_series_a = sum(funding)