<?php

/** Simple Rules Engine **/
class Container {
    protected $_data = array();
    public function __set ($key, $value) {
        $this->_data[$key] = $value;
    }
    public function __get ($key) {
        if (!isset($this->_data[$key])) {
            throw new Exception("{$key} is not a valid key.");
        }
        if (is_callable($this->_data[$key])) {
            return $this->_data[$key]($this);
        }
        return $this->_data[$key];
    }
}

class Factory {
    protected static $rules = array();
    public static function Rule ($rule) {
        if (!isset(self::$rules[$rule])) {
            self::$rules[$rule] = new Rule($rule);
        }

        return self::$rules[$rule];
    }

    protected static $rule_groups = array();
    public static function RuleGroup ($group) {
        if (!isset(self::$rule_groups[$group])) {
            self::$rule_groups[$group] = new RuleGroup($group);
        }

        return self::$rule_groups[$group];
    }
}

class RuleGroup extends Container {
    public function __construct ($name) {
        $this->group_name = $name;
    }

    public function set_rules ($rules) {
        $this->rules = $rules;
    }

    public function execute ($value) {
        foreach ($this->rules as $rule) {
            $rule->value = $value;
            $rule->execute();
            $value = $rule->value;
        }

        return $value;
    }
}

class Rule extends Container {
    public function __construct ($rule) {
        $this->rule = $rule;

        $this->condition = function ($context) {
            return false;
        };
        $this->then = function ($context) {};
    }
    public function execute () {
        if ($this->condition) {
            $this->then;
        }
    }

}

$rule = Factory::Rule('If value is less than 10, add 1');
$rule->condition = function ($context) {
    return $context->value < 10;
};
$rule->then = function ($context) {
    $context->value = $context->value + 1;
};

$rule = Factory::Rule('If value is divisible by 3, divide by 3');
$rule->condition = function ($context) {
    return $context->value % 3 == 0;
};
$rule->then = function ($context) {
    $context->value = $context->value / 3;
};

$rule_group = Factory::RuleGroup('Add 1, divide by 3');
$rule_group->set_rules(array(
    Factory::Rule('If value is less than 10, add 1'),
    Factory::Rule('If value is divisible by 3, divide by 3')
    ));


?>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>Rules Engine Testing</title>
</head>
<body>
    <?php foreach (range(1, 3) as $value): ?>
    <fieldset>
        <legend>Current Value being tested: <?= $value ?></legend>
        <?php
        $rule = Factory::Rule('If value is less than 10, add 1');
        $rule->value = $value;
        $rule->execute();
        ?>
        <div>
            <strong><?= $rule->rule ?></strong><br>
            <p>Start value = <?= $value ?> -- End value = <?= $rule->value ?></p>
        </div>
        
        <?php $value = $rule->value; ?>

        <?php
        $rule = Factory::Rule('If value is divisible by 3, divide by 3');
        $rule->value = $value;
        $rule->execute();
        ?>
        <div>
            <strong><?= $rule->rule ?></strong><br>
            <p>Start value = <?= $value ?> -- End value = <?= $rule->value ?></p>
        </div>
    </fieldset>
    <?php endforeach; ?>

    <?php foreach (range(1, 3) as $value): ?>
        <fieldset>
            <legend>Current Value being run through the group: <?= $value ?></legend>
            <?php
                $rule_group = Factory::RuleGroup('Add 1, divide by 3');
                $ending_value = $rule_group->execute($value); 
            ?>
            <div>Starting Value: <?= $value ?> -- Ending Value: <?= $ending_value ?></div>
        </fieldset>
    <?php endforeach; ?>
</body>
</html>