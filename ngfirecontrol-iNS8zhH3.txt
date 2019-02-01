;angular.module('nynApplication')
.controller('nynFireControl', ['$scope', '$rootScope', function($scope, $rootScope){
	$scope.dispatcher = {
		registered: false
		, events: [

		]
		, fetch_event: function(receive){
			var len = this.events.length;
			while(len--){
				if(receive == this.events[len].receive) return this.events[len];
			}
		}
		, broadcast: function(event, params){
			$rootScope.$broadcast(event, params);
		}
		, receive: function(event, params){
			var e = this.fetch_event(event.name);
			this.broadcast(e.broadcast, params);
		}
		, __init: function(){
			if(this.registered) return;
			var len = this.events.length;
			while(len--){
				$rootScope.$on(this.events[len].receive, this.receive);
			}

			this.registered = true;
		}
	};

	$scope.dispatcher.__init();
}])