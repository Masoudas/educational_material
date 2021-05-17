/**
* The term and primary functions follows the same logic as the expression function:

double term(bool get) // multiply and divide
{
	double left = prim(get);
	
	for (;;) {
		switch (ts.current().kind) {
		case Kind::mul:
			left *= prim(true);
		break;
		case Kind::div:
			if (auto d = prim(true)) {
				left /= d;
			break;
			}
			return error("divide by 0");
		default:
			return left;
		}
	}
}

double prim(bool get) // handle primar ies
{
	if (get) ts.get(); // read next token
		switch (ts.current().kind) {
		case Kind::number: // floating-point constant
			{ double v = ts.current().number_value;
			  ts.get();
			  return v;
			}
		case Kind::name:
			{ double& v = table[ts.current().string_value]; // find the corresponding
			  if (ts.get().kind == Kind::assign) v = expr(true); // ’=’ seen: assignment
			  return v;
			}
		case Kind::minus: // unar y minus
		return -prim(true);
		case Kind::lp:
		{ auto e = expr(true);
			if (ts.current().kind != Kind::rp) return error("')' expected");
			ts.get(); // eat ’)’
			return e;
		}
		
		default:
		return error("primar y expected");
	}
}



*/