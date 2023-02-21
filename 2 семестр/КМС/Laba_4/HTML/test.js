(function (cjs, an) {

var p; // shortcut to reference prototypes
var lib={};var ss={};var img={};
lib.ssMetadata = [
		{name:"test_atlas_1", frames: [[1433,786,249,132],[1684,919,248,130],[1433,1050,246,128],[1681,1179,244,126],[1433,1180,243,124],[1681,1051,245,126],[1433,1306,243,123],[1433,920,247,128],[1678,1307,241,121],[1026,786,405,572],[1684,786,249,131],[1026,452,926,332],[0,0,1024,495],[0,497,1024,495],[0,994,1024,495],[0,1491,1024,495],[1026,0,798,450]]}
];


(lib.AnMovieClip = function(){
	this.currentSoundStreamInMovieclip;
	this.actionFrames = [];
	this.soundStreamDuration = new Map();
	this.streamSoundSymbolsList = [];

	this.gotoAndPlayForStreamSoundSync = function(positionOrLabel){
		cjs.MovieClip.prototype.gotoAndPlay.call(this,positionOrLabel);
	}
	this.gotoAndPlay = function(positionOrLabel){
		this.clearAllSoundStreams();
		this.startStreamSoundsForTargetedFrame(positionOrLabel);
		cjs.MovieClip.prototype.gotoAndPlay.call(this,positionOrLabel);
	}
	this.play = function(){
		this.clearAllSoundStreams();
		this.startStreamSoundsForTargetedFrame(this.currentFrame);
		cjs.MovieClip.prototype.play.call(this);
	}
	this.gotoAndStop = function(positionOrLabel){
		cjs.MovieClip.prototype.gotoAndStop.call(this,positionOrLabel);
		this.clearAllSoundStreams();
	}
	this.stop = function(){
		cjs.MovieClip.prototype.stop.call(this);
		this.clearAllSoundStreams();
	}
	this.startStreamSoundsForTargetedFrame = function(targetFrame){
		for(var index=0; index<this.streamSoundSymbolsList.length; index++){
			if(index <= targetFrame && this.streamSoundSymbolsList[index] != undefined){
				for(var i=0; i<this.streamSoundSymbolsList[index].length; i++){
					var sound = this.streamSoundSymbolsList[index][i];
					if(sound.endFrame > targetFrame){
						var targetPosition = Math.abs((((targetFrame - sound.startFrame)/lib.properties.fps) * 1000));
						var instance = playSound(sound.id);
						var remainingLoop = 0;
						if(sound.offset){
							targetPosition = targetPosition + sound.offset;
						}
						else if(sound.loop > 1){
							var loop = targetPosition /instance.duration;
							remainingLoop = Math.floor(sound.loop - loop);
							if(targetPosition == 0){ remainingLoop -= 1; }
							targetPosition = targetPosition % instance.duration;
						}
						instance.loop = remainingLoop;
						instance.position = Math.round(targetPosition);
						this.InsertIntoSoundStreamData(instance, sound.startFrame, sound.endFrame, sound.loop , sound.offset);
					}
				}
			}
		}
	}
	this.InsertIntoSoundStreamData = function(soundInstance, startIndex, endIndex, loopValue, offsetValue){ 
 		this.soundStreamDuration.set({instance:soundInstance}, {start: startIndex, end:endIndex, loop:loopValue, offset:offsetValue});
	}
	this.clearAllSoundStreams = function(){
		var keys = this.soundStreamDuration.keys();
		for(var i = 0;i<this.soundStreamDuration.size; i++){
			var key = keys.next().value;
			key.instance.stop();
		}
 		this.soundStreamDuration.clear();
		this.currentSoundStreamInMovieclip = undefined;
	}
	this.stopSoundStreams = function(currentFrame){
		if(this.soundStreamDuration.size > 0){
			var keys = this.soundStreamDuration.keys();
			for(var i = 0; i< this.soundStreamDuration.size ; i++){
				var key = keys.next().value; 
				var value = this.soundStreamDuration.get(key);
				if((value.end) == currentFrame){
					key.instance.stop();
					if(this.currentSoundStreamInMovieclip == key) { this.currentSoundStreamInMovieclip = undefined; }
					this.soundStreamDuration.delete(key);
				}
			}
		}
	}

	this.computeCurrentSoundStreamInstance = function(currentFrame){
		if(this.currentSoundStreamInMovieclip == undefined){
			if(this.soundStreamDuration.size > 0){
				var keys = this.soundStreamDuration.keys();
				var maxDuration = 0;
				for(var i=0;i<this.soundStreamDuration.size;i++){
					var key = keys.next().value;
					var value = this.soundStreamDuration.get(key);
					if(value.end > maxDuration){
						maxDuration = value.end;
						this.currentSoundStreamInMovieclip = key;
					}
				}
			}
		}
	}
	this.getDesiredFrame = function(currentFrame, calculatedDesiredFrame){
		for(var frameIndex in this.actionFrames){
			if((frameIndex > currentFrame) && (frameIndex < calculatedDesiredFrame)){
				return frameIndex;
			}
		}
		return calculatedDesiredFrame;
	}

	this.syncStreamSounds = function(){
		this.stopSoundStreams(this.currentFrame);
		this.computeCurrentSoundStreamInstance(this.currentFrame);
		if(this.currentSoundStreamInMovieclip != undefined){
			var soundInstance = this.currentSoundStreamInMovieclip.instance;
			if(soundInstance.position != 0){
				var soundValue = this.soundStreamDuration.get(this.currentSoundStreamInMovieclip);
				var soundPosition = (soundValue.offset?(soundInstance.position - soundValue.offset): soundInstance.position);
				var calculatedDesiredFrame = (soundValue.start)+((soundPosition/1000) * lib.properties.fps);
				if(soundValue.loop > 1){
					calculatedDesiredFrame +=(((((soundValue.loop - soundInstance.loop -1)*soundInstance.duration)) / 1000) * lib.properties.fps);
				}
				calculatedDesiredFrame = Math.floor(calculatedDesiredFrame);
				var deltaFrame = calculatedDesiredFrame - this.currentFrame;
				if(deltaFrame >= 2){
					this.gotoAndPlayForStreamSoundSync(this.getDesiredFrame(this.currentFrame,calculatedDesiredFrame));
				}
			}
		}
	}
}).prototype = p = new cjs.MovieClip();
// symbols:



(lib.CachedBmp_22 = function() {
	this.initialize(ss["test_atlas_1"]);
	this.gotoAndStop(0);
}).prototype = p = new cjs.Sprite();



(lib.CachedBmp_21 = function() {
	this.initialize(ss["test_atlas_1"]);
	this.gotoAndStop(1);
}).prototype = p = new cjs.Sprite();



(lib.CachedBmp_20 = function() {
	this.initialize(ss["test_atlas_1"]);
	this.gotoAndStop(2);
}).prototype = p = new cjs.Sprite();



(lib.CachedBmp_19 = function() {
	this.initialize(ss["test_atlas_1"]);
	this.gotoAndStop(3);
}).prototype = p = new cjs.Sprite();



(lib.CachedBmp_16 = function() {
	this.initialize(ss["test_atlas_1"]);
	this.gotoAndStop(4);
}).prototype = p = new cjs.Sprite();



(lib.CachedBmp_15 = function() {
	this.initialize(ss["test_atlas_1"]);
	this.gotoAndStop(5);
}).prototype = p = new cjs.Sprite();



(lib.CachedBmp_18 = function() {
	this.initialize(ss["test_atlas_1"]);
	this.gotoAndStop(6);
}).prototype = p = new cjs.Sprite();



(lib.CachedBmp_14 = function() {
	this.initialize(ss["test_atlas_1"]);
	this.gotoAndStop(7);
}).prototype = p = new cjs.Sprite();



(lib.CachedBmp_17 = function() {
	this.initialize(ss["test_atlas_1"]);
	this.gotoAndStop(8);
}).prototype = p = new cjs.Sprite();



(lib.CachedBmp_23 = function() {
	this.initialize(ss["test_atlas_1"]);
	this.gotoAndStop(9);
}).prototype = p = new cjs.Sprite();



(lib.CachedBmp_13 = function() {
	this.initialize(ss["test_atlas_1"]);
	this.gotoAndStop(10);
}).prototype = p = new cjs.Sprite();



(lib.CachedBmp_12 = function() {
	this.initialize(ss["test_atlas_1"]);
	this.gotoAndStop(11);
}).prototype = p = new cjs.Sprite();



(lib.CachedBmp_4 = function() {
	this.initialize(ss["test_atlas_1"]);
	this.gotoAndStop(12);
}).prototype = p = new cjs.Sprite();



(lib.CachedBmp_3 = function() {
	this.initialize(ss["test_atlas_1"]);
	this.gotoAndStop(13);
}).prototype = p = new cjs.Sprite();



(lib.CachedBmp_1 = function() {
	this.initialize(ss["test_atlas_1"]);
	this.gotoAndStop(14);
}).prototype = p = new cjs.Sprite();



(lib.CachedBmp_2 = function() {
	this.initialize(ss["test_atlas_1"]);
	this.gotoAndStop(15);
}).prototype = p = new cjs.Sprite();



(lib.CachedBmp_8 = function() {
	this.initialize(ss["test_atlas_1"]);
	this.gotoAndStop(16);
}).prototype = p = new cjs.Sprite();



(lib.ТелоЖука = function(mode,startPosition,loop) {
	this.initialize(mode,startPosition,loop,{});

	// Слой_1
	this.instance = new lib.CachedBmp_23();
	this.instance.setTransform(-128.9,-178.25,0.5,0.5);

	this.timeline.addTween(cjs.Tween.get(this.instance).wait(1));

	this._renderFirstFrame();

}).prototype = p = new cjs.MovieClip();
p.nominalBounds = new cjs.Rectangle(-128.9,-178.2,202.5,286);


(lib.ЛапаЖука = function(mode,startPosition,loop) {
	this.initialize(mode,startPosition,loop,{});

	// Слой_1
	this.instance = new lib.CachedBmp_13();
	this.instance.setTransform(-2.9,-32.3,0.4463,0.4463);

	this.instance_1 = new lib.CachedBmp_14();
	this.instance_1.setTransform(-2.95,-36.2,0.4463,0.4463);

	this.instance_2 = new lib.CachedBmp_15();
	this.instance_2.setTransform(-3.05,-40.1,0.4463,0.4463);

	this.instance_3 = new lib.CachedBmp_16();
	this.instance_3.setTransform(-3.15,-44,0.4463,0.4463);

	this.instance_4 = new lib.CachedBmp_17();
	this.instance_4.setTransform(-3.25,-47.95,0.4463,0.4463);

	this.instance_5 = new lib.CachedBmp_18();
	this.instance_5.setTransform(-3.1,-43.7,0.4463,0.4463);

	this.instance_6 = new lib.CachedBmp_19();
	this.instance_6.setTransform(-3,-39.45,0.4463,0.4463);

	this.instance_7 = new lib.CachedBmp_20();
	this.instance_7.setTransform(-2.9,-35.25,0.4463,0.4463);

	this.instance_8 = new lib.CachedBmp_21();
	this.instance_8.setTransform(-2.85,-31,0.4463,0.4463);

	this.instance_9 = new lib.CachedBmp_22();
	this.instance_9.setTransform(-2.7,-26.8,0.4463,0.4463);

	this.timeline.addTween(cjs.Tween.get({}).to({state:[{t:this.instance}]}).to({state:[{t:this.instance_1}]},1).to({state:[{t:this.instance_2}]},1).to({state:[{t:this.instance_3}]},1).to({state:[{t:this.instance_4}]},1).to({state:[{t:this.instance_5}]},1).to({state:[{t:this.instance_6}]},1).to({state:[{t:this.instance_7}]},1).to({state:[{t:this.instance_8}]},1).to({state:[{t:this.instance_9}]},1).wait(1));

	this._renderFirstFrame();

}).prototype = p = new cjs.MovieClip();
p.nominalBounds = new cjs.Rectangle(-3.2,-47.9,111.60000000000001,80);


(lib.Стоп = function(mode,startPosition,loop) {
	this.initialize(mode,startPosition,loop,{});

	// Слой_1
	this.instance = new lib.CachedBmp_12();
	this.instance.setTransform(-271.5,-43.45,0.5,0.5);

	this.timeline.addTween(cjs.Tween.get(this.instance).wait(1).to({x:-219.5,y:-67},0).wait(3));

	this._renderFirstFrame();

}).prototype = p = new cjs.MovieClip();
p.nominalBounds = new cjs.Rectangle(-271.5,-67,515,189.6);


(lib.Пуск = function(mode,startPosition,loop) {
	this.initialize(mode,startPosition,loop,{});

	// Слой_1
	this.instance = new lib.CachedBmp_8();
	this.instance.setTransform(-248.65,-128.6,0.5,0.5);

	this.timeline.addTween(cjs.Tween.get(this.instance).wait(1).to({x:-142.5,y:-69.5},0).wait(3));

	this._renderFirstFrame();

}).prototype = p = new cjs.MovieClip();
p.nominalBounds = new cjs.Rectangle(-248.6,-128.6,505.1,284.1);


(lib.Назад = function(mode,startPosition,loop) {
	this.initialize(mode,startPosition,loop,{});

	// Слой_1
	this.instance = new lib.CachedBmp_1();
	this.instance.setTransform(-291.45,-113.05,0.5,0.5);

	this.instance_1 = new lib.CachedBmp_2();
	this.instance_1.setTransform(-193.1,-107.65,0.5,0.5);

	this.instance_2 = new lib.CachedBmp_3();
	this.instance_2.setTransform(-193.1,-107.65,0.5,0.5);

	this.instance_3 = new lib.CachedBmp_4();
	this.instance_3.setTransform(-193.1,-107.65,0.5,0.5);

	this.timeline.addTween(cjs.Tween.get({}).to({state:[{t:this.instance}]}).to({state:[{t:this.instance_1}]},1).to({state:[{t:this.instance_2}]},1).to({state:[{t:this.instance_3}]},1).wait(1));

	this._renderFirstFrame();

}).prototype = p = new cjs.MovieClip();
p.nominalBounds = new cjs.Rectangle(-291.4,-113,610.3,252.9);


(lib.Жук = function(mode,startPosition,loop) {
	this.initialize(mode,startPosition,loop,{});

	// Слой_1
	this.instance = new lib.ЛапаЖука("synched",0);
	this.instance.setTransform(7.3,103.25,0.9999,0.9895,0,-149.9998,29.9987,52.5,-7.9);

	this.instance_1 = new lib.ЛапаЖука("synched",0);
	this.instance_1.setTransform(-176.55,91.55,1.1204,1.0621,0,-29.9973,150.0015,52.5,-7.8);

	this.instance_2 = new lib.ЛапаЖука("synched",0);
	this.instance_2.setTransform(11.35,38.4,1,0.9896,0,165.001,-15.0007,52.5,-7.9);

	this.instance_3 = new lib.ЛапаЖука("synched",0);
	this.instance_3.setTransform(-177.95,22.7,0.9136,0.9231,0,14.9979,-165.0019,52.7,-8);

	this.instance_4 = new lib.ЛапаЖука("synched",0);
	this.instance_4.setTransform(6.95,-30.55,1,1,-15.0007,0,0,52.6,-7.9);

	this.instance_5 = new lib.ЛапаЖука("synched",0);
	this.instance_5.setTransform(-179.2,-15.2,1,1,-165.0017,0,0,52.6,-7.9);

	this.instance_6 = new lib.ТелоЖука("synched",0);
	this.instance_6.setTransform(-117.25,-9.9,1,1,0,0,0,-27.8,-35.2);

	this.timeline.addTween(cjs.Tween.get({}).to({state:[{t:this.instance_6},{t:this.instance_5,p:{startPosition:0}},{t:this.instance_4,p:{startPosition:0}},{t:this.instance_3,p:{startPosition:0}},{t:this.instance_2,p:{startPosition:0}},{t:this.instance_1,p:{startPosition:0}},{t:this.instance,p:{startPosition:0}}]}).to({state:[{t:this.instance_6},{t:this.instance_5,p:{startPosition:9}},{t:this.instance_4,p:{startPosition:9}},{t:this.instance_3,p:{startPosition:9}},{t:this.instance_2,p:{startPosition:9}},{t:this.instance_1,p:{startPosition:9}},{t:this.instance,p:{startPosition:9}}]},9).wait(1));

	this._renderFirstFrame();

}).prototype = p = new cjs.MovieClip();
p.nominalBounds = new cjs.Rectangle(-248.1,-152.9,323.7,316.4);


// stage content:
(lib.test = function(mode,startPosition,loop) {
	this.initialize(mode,startPosition,loop,{});

	this.actionFrames = [0,44];
	this.streamSoundSymbolsList[0] = [{id:"Жук1",startFrame:0,endFrame:100,loop:1,offset:702}];
	// timeline functions:
	this.frame_0 = function() {
		this.clearAllSoundStreams();
		 
		var soundInstance = playSound("Жук1",0,702);
		this.InsertIntoSoundStreamData(soundInstance,0,100,1,702);
		/* Событие щелчка мыши
		При нажатии на указанный экземпляр символа выполняется функция, в которую можно добавить собственный код.
		
		Инструкции:
		1. Добавьте пользовательский код после строки "// Начало пользовательского кода".
		Этот код будет выполнен после нажатия на экземпляр символа.
		*/
		
		this.stop();
		this.button_3.addEventListener("click", fl_MouseClickHandler_3.bind(this));
		
		function fl_MouseClickHandler_3()
		{
			// Начало пользовательского кода
			// Этот образец кода отображает в панели "Вывод" слова "Нажата кнопка мыши".
			
			this.play();
			// Конец пользовательского кода
		}
		
		/* Событие щелчка мыши
		При нажатии на указанный экземпляр символа выполняется функция, в которую можно добавить собственный код.
		
		Инструкции:
		1. Добавьте пользовательский код после строки "// Начало пользовательского кода".
		Этот код будет выполнен после нажатия на экземпляр символа.
		*/
		
		this.Stops.addEventListener("click", fl_MouseClickHandler_4.bind(this));
		
		function fl_MouseClickHandler_4()
		{
			// Начало пользовательского кода
			// Этот образец кода отображает в панели "Вывод" слова "Нажата кнопка мыши".
		this.stop();
		}
		
		/* Событие щелчка мыши
		При нажатии на указанный экземпляр символа выполняется функция, в которую можно добавить собственный код.
		
		Инструкции:
		1. Добавьте пользовательский код после строки "// Начало пользовательского кода".
		Этот код будет выполнен после нажатия на экземпляр символа.
		*/
		
		this.Prev.addEventListener("click", fl_MouseClickHandler_5.bind(this));
		
		function fl_MouseClickHandler_5()
		{
			this.gotoAndStop(0);
		}
	}
	this.frame_44 = function() {
		playSound("Жук2");
	}

	// actions tween:
	this.timeline.addTween(cjs.Tween.get(this).call(this.frame_0).wait(44).call(this.frame_44).wait(56));

	// Жук1
	this.instance = new lib.Жук();
	this.instance.setTransform(-3.9,533.75,1,1,67.6968,0,0,-88.2,6.2);

	this.timeline.addTween(cjs.Tween.get(this.instance).to({x:714.6,y:305.8},59).to({rotation:157.6968,guide:{path:[714.6,305.8,722.5,300.7,730.6,295.3,843,219.5,913.9,64.7,971.6,-61.5,1083.5,117.6], orient:'fixed'}},20).to({guide:{path:[1083.5,117.6,1109,158.3,1137.2,214.8,1168.7,277.6,1115.7,328.6,1062.6,379.6,1043.3,411.7,1024,443.9,1045.7,447.6,1071.7,452.1,1098.8,450.5,1114.4,449.7,1130,448.7,1148.6,447.5,1167.3,444.4,1190.8,440.5,1258.4,518.9], orient:'fixed'}},20).wait(1));

	// Жуки
	this.instance_1 = new lib.Жук();
	this.instance_1.setTransform(746.45,45.3,0.2775,0.3962,88.02,0,0,-88,6.1);

	this.instance_2 = new lib.Жук();
	this.instance_2.setTransform(510.4,647.1,0.6845,0.8626,-1.9809,0,0,-88.1,6.1);

	this.instance_3 = new lib.Жук();
	this.instance_3.setTransform(872,667.45,0.3932,0.6348,0,0,0,-88.2,6.2);

	this.instance_4 = new lib.Жук();
	this.instance_4.setTransform(108.65,101.05,0.3932,0.6348,0,0,0,-88.2,6.2);

	this.timeline.addTween(cjs.Tween.get({}).to({state:[{t:this.instance_4},{t:this.instance_3},{t:this.instance_2},{t:this.instance_1}]}).wait(100));

	// buttons
	this.Prev = new lib.Назад();
	this.Prev.name = "Prev";
	this.Prev.setTransform(1057.4,659.65,0.3459,0.3408);
	new cjs.ButtonHelper(this.Prev, 0, 1, 2, false, new lib.Назад(), 3);

	this.Stops = new lib.Стоп();
	this.Stops.name = "Stops";
	this.Stops.setTransform(850.25,531.5,0.451,0.2552);
	new cjs.ButtonHelper(this.Stops, 0, 1, 2, false, new lib.Стоп(), 3);

	this.button_3 = new lib.Пуск();
	this.button_3.name = "button_3";
	this.button_3.setTransform(1156.15,555.45,0.4616,0.4628,0,0,-3.1378,0.2,0.1);
	new cjs.ButtonHelper(this.button_3, 0, 1, 2, false, new lib.Пуск(), 3);

	this.timeline.addTween(cjs.Tween.get({}).to({state:[{t:this.button_3},{t:this.Stops},{t:this.Prev}]}).wait(100));

	// Жук2
	this.instance_5 = new lib.Жук();
	this.instance_5.setTransform(1197.1,118.1,0.5017,0.6229,-90,0,0,-88.4,6.2);

	this.timeline.addTween(cjs.Tween.get(this.instance_5).to({guide:{path:[1197.1,118.2,1092,193.7,986.9,269.2,986.9,271.9,986.9,274.5,938.3,303.2,889.6,331.8,881.5,335.7,873.4,339.6]}},59).to({rotation:-210.0004,guide:{path:[873.4,339.6,802.5,373.9,731.5,408.3,699.7,418.2,667.8,428.1]}},20).to({regX:-88.5,rotation:-104.998,guide:{path:[667.8,428.1,554.6,463.3,441.4,498.6,433.5,498.6,425.7,498.6,359.7,522.9,293.8,547.3]}},20).wait(1));

	this._renderFirstFrame();

}).prototype = p = new lib.AnMovieClip();
p.nominalBounds = new cjs.Rectangle(452.2,189.9,987.0999999999999,587.6);
// library properties:
lib.properties = {
	id: '689871AB8ED02646B2BF547D7ED6CAC1',
	width: 1280,
	height: 720,
	fps: 30,
	color: "#FFFFFF",
	opacity: 1.00,
	manifest: [
		{src:"images/test_atlas_1.png?1676995835017", id:"test_atlas_1"},
		{src:"sounds/Жук1.mp3?1676995835067", id:"Жук1"},
		{src:"sounds/Жук2.mp3?1676995835067", id:"Жук2"}
	],
	preloads: []
};



// bootstrap callback support:

(lib.Stage = function(canvas) {
	createjs.Stage.call(this, canvas);
}).prototype = p = new createjs.Stage();

p.setAutoPlay = function(autoPlay) {
	this.tickEnabled = autoPlay;
}
p.play = function() { this.tickEnabled = true; this.getChildAt(0).gotoAndPlay(this.getTimelinePosition()) }
p.stop = function(ms) { if(ms) this.seek(ms); this.tickEnabled = false; }
p.seek = function(ms) { this.tickEnabled = true; this.getChildAt(0).gotoAndStop(lib.properties.fps * ms / 1000); }
p.getDuration = function() { return this.getChildAt(0).totalFrames / lib.properties.fps * 1000; }

p.getTimelinePosition = function() { return this.getChildAt(0).currentFrame / lib.properties.fps * 1000; }

an.bootcompsLoaded = an.bootcompsLoaded || [];
if(!an.bootstrapListeners) {
	an.bootstrapListeners=[];
}

an.bootstrapCallback=function(fnCallback) {
	an.bootstrapListeners.push(fnCallback);
	if(an.bootcompsLoaded.length > 0) {
		for(var i=0; i<an.bootcompsLoaded.length; ++i) {
			fnCallback(an.bootcompsLoaded[i]);
		}
	}
};

an.compositions = an.compositions || {};
an.compositions['689871AB8ED02646B2BF547D7ED6CAC1'] = {
	getStage: function() { return exportRoot.stage; },
	getLibrary: function() { return lib; },
	getSpriteSheet: function() { return ss; },
	getImages: function() { return img; }
};

an.compositionLoaded = function(id) {
	an.bootcompsLoaded.push(id);
	for(var j=0; j<an.bootstrapListeners.length; j++) {
		an.bootstrapListeners[j](id);
	}
}

an.getComposition = function(id) {
	return an.compositions[id];
}


an.makeResponsive = function(isResp, respDim, isScale, scaleType, domContainers) {		
	var lastW, lastH, lastS=1;		
	window.addEventListener('resize', resizeCanvas);		
	resizeCanvas();		
	function resizeCanvas() {			
		var w = lib.properties.width, h = lib.properties.height;			
		var iw = window.innerWidth, ih=window.innerHeight;			
		var pRatio = window.devicePixelRatio || 1, xRatio=iw/w, yRatio=ih/h, sRatio=1;			
		if(isResp) {                
			if((respDim=='width'&&lastW==iw) || (respDim=='height'&&lastH==ih)) {                    
				sRatio = lastS;                
			}				
			else if(!isScale) {					
				if(iw<w || ih<h)						
					sRatio = Math.min(xRatio, yRatio);				
			}				
			else if(scaleType==1) {					
				sRatio = Math.min(xRatio, yRatio);				
			}				
			else if(scaleType==2) {					
				sRatio = Math.max(xRatio, yRatio);				
			}			
		}			
		domContainers[0].width = w * pRatio * sRatio;			
		domContainers[0].height = h * pRatio * sRatio;			
		domContainers.forEach(function(container) {				
			container.style.width = w * sRatio + 'px';				
			container.style.height = h * sRatio + 'px';			
		});			
		stage.scaleX = pRatio*sRatio;			
		stage.scaleY = pRatio*sRatio;			
		lastW = iw; lastH = ih; lastS = sRatio;            
		stage.tickOnUpdate = false;            
		stage.update();            
		stage.tickOnUpdate = true;		
	}
}
an.handleSoundStreamOnTick = function(event) {
	if(!event.paused){
		var stageChild = stage.getChildAt(0);
		if(!stageChild.paused){
			stageChild.syncStreamSounds();
		}
	}
}


})(createjs = createjs||{}, AdobeAn = AdobeAn||{});
var createjs, AdobeAn;