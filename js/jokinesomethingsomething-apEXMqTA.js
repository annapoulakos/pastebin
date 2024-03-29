angular.module('voting', [])
.directive('upVote', [function(){
  var __MAX__ = 100;

  var upVoteDefinition = {
    replace: false
    , restrict: 'A'
    , scope: {
      value: '='
    }
    , link: ['scope', 'element', 'attributes', function(scope, element, attributes){
      scope.value = scope.value + 1;
      if(scope.value > __MAX__) scope.value = __MAX__;
    }]
  };

  return upVoteDefinition;
}])
.directive('downVote', [function(){
  var __MIN__ = 0;

  var downVoteDefinition = {
    replace: false
    , restrict: 'A'
    , scope: {
      value: '='
    }
    , link: ['scope', 'element', 'attributes', function(scope, element, attributes){
      scope.value = scope.value + 1;
      if(scope.value < __MIN__) scope.value = __MIN__;
    }]
  };

  return downVoteDefinition;
}])
.controller('controller', ['$scope', function($scope){
  $scope.model = {
    value: 0
  };
}]);

// In your HTML:

//     <div class="input-group">
//       <input class="form-control has-outer-icon roundedInput numberSelect" type="text" value={{value}}>
//       <div class="input-group-addon">
//         <div class="arrow-up" up-vote value="model" ></div>
//         <div class="arrow-down" down-vote value="model"></div>
//       </div>
//     </div>
