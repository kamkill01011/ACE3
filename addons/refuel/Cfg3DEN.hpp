#define GET_NUMBER(config,default) (if (isNumber (config)) then {getNumber (config)} else {default})
#define GET_1ST_ARRAY(config) (if (isArray (config)) then {getArray (config) select 0} else {[ARR_3(0,0,0)]})

#define DEFAULT_FUELCARGO GET_NUMBER(configOf _this >> QQGVAR(fuelCargo),REFUEL_DISABLED_FUEL)
#define DEFAULT_HOOKS GET_1ST_ARRAY(configOf _this >> QQGVAR(hooks))

class Cfg3DEN {
    class Object {
        class AttributeCategories {
            class ace_attributes {
                class Attributes {
                    class GVAR(fuelCargo) {
                        displayName = CSTRING(fuelCargo_edenName);
                        tooltip = CSTRING(fuelCargo_edenDesc);
                        property = QGVAR(fuelCargo);
                        control = "EditShort";
                        //expression = QUOTE(if (_value != DEFAULT_FUELCARGO) then {[ARR_2(_this,_value)] call DFUNC(makeSource)});
						expression = "if (_value != (if (isNumber (configOf _this >> ""ace_refuel_fuelCargo"")) then {getNumber (configOf _this >> ""ace_refuel_fuelCargo"")} else {-1})) then {[_this, _value] call ace_refuel_fnc_makeSource}";
                        //defaultValue = QUOTE(DEFAULT_FUELCARGO);
						defaultValue = "(if (isNumber (configOf _this >> ""ace_refuel_fuelCargo"")) then {getNumber (configOf _this >> ""ace_refuel_fuelCargo"")} else {-1})";
                        validate = "number";
                        condition = "(1-objectBrain)*(1-objectAgent)";
                        typeName = "NUMBER";
                    };
                    class GVAR(hooks) {
                        displayName = CSTRING(hooks_edenName);
                        tooltip = CSTRING(hooks_edenDesc);
                        property = QGVAR(hooks);
                        control = "EditXYZ";
                        //expression = QUOTE(if (_value isNotEqualTo DEFAULT_HOOKS) then {_this setVariable [ARR_3('%s',[_value],true)]});
						expression = "if (_value isNotEqualTo (if (isArray (configOf _this >> ""ace_refuel_hooks"")) then {getArray (configOf _this >> ""ace_refuel_hooks"") select 0} else {[0, 0, 0]})) then {_this setVariable ['%s', [_value], true]}";
                        //defaultValue = QUOTE(DEFAULT_HOOKS);
						defaultValue = "(if (isArray (configOf _this >> ""ace_refuel_hooks"")) then {getArray (configOf _this >> ""ace_refuel_hooks"") select 0} else {[0, 0, 0]})";
                        condition = "(1-objectBrain)*(1-objectAgent)";
                    };
                };
            };
        };
    };
};
